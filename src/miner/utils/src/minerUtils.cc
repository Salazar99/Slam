#include "minerUtils.hh"
#include "Hierarchical.hh"
#include "KDE.hh"
#include "Kmeans.hh"
#include "Template.hh"
#include "globals.hh"

namespace slam {

std::ostream &operator<<(std::ostream &os, ClsOp op) {
  switch (op) {
  case ClsOp::Range:
    os << "r";
    break;
  case ClsOp::E:
    os << "e";
    break;
  case ClsOp::GE:
    os << "ge";
    break;
  case ClsOp::LE:
    os << "le";
    break;
  }
  return os;
}

std::pair<VarType, size_t> variableTypeFromString(const std::string &type,
                                                  size_t size) {
  if (type == "bool") {
    return std::make_pair(VarType::Bool, 1);
  } else if (type == "char") {
    return std::make_pair(VarType::SLogic, 8);
  } else if (type == "short") {
    return std::make_pair(VarType::SLogic, 16);
  } else if (type == "int") {
    return std::make_pair(VarType::SLogic, 32);
  } else if (type == "long int") {
    return std::make_pair(VarType::SLogic, 64);
  } else if (type == "unsigned char") {
    return std::make_pair(VarType::ULogic, 8);
  } else if (type == "unsigned short") {
    return std::make_pair(VarType::ULogic, 16);
  } else if (type == "unsigned int") {
    return std::make_pair(VarType::ULogic, 32);
  } else if (type == "unsigned long int") {
    return std::make_pair(VarType::ULogic, 64);
  } else if (type == "float") {
    return std::make_pair(VarType::Numeric, 32);
  } else if (type == "double") {
    return std::make_pair(VarType::Numeric, 64);
  } else if (type == "integer") {
    return std::make_pair(VarType::SLogic, 32);

  } else if (type == "byte") {
    return std::make_pair(VarType::SLogic, 8);
  } else if (type == "shortint") {
    return std::make_pair(VarType::SLogic, 16);
  } else if (type == "longint") {
    return std::make_pair(VarType::SLogic, 64);
  } else if (type == "byte unsigned") {
    return std::make_pair(VarType::ULogic, 8);
  } else if (type == "shortint unsigned") {
    return std::make_pair(VarType::ULogic, 16);
  } else if (type == "longint unsigned") {
    return std::make_pair(VarType::ULogic, 64);
  } else if (type == "time") {
    return std::make_pair(VarType::ULogic, 64);
  } else if (type == "shortreal") {
    return std::make_pair(VarType::Numeric, 32);
  } else if (type == "real") {
    return std::make_pair(VarType::Numeric, 64);
  } else if (type == "reg") {
    return std::make_pair(VarType::ULogic, size);
  } else if (type == "wire") {
    return std::make_pair(VarType::ULogic, size);
  } else if (type == "logic") {
    return std::make_pair(VarType::ULogic, size);
  } else if (type == "bit") {
    return std::make_pair(VarType::ULogic, size);
  }

  messageError("Unknown type: " + type);

  return std::make_pair(VarType::Bool, 1);
}

template <typename T>
std::vector<std::pair<
    Proposition *,
    std::pair<size_t,
              size_t>>> inline makeLogicRange(std::
                                                  vector<std::pair<
                                                      std::pair<T, T>,
                                                      std::pair<size_t,
                                                                size_t>>>
                                                      &clusters,
                                              std::pair<VarType, T> type,
                                              CachedAllNumeric *cn) {

  std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> ret;
  for (auto &c : clusters) {
    if (c.first.first != c.first.second) {
      if (cn->_clsOps.count(ClsOp::Range)) {
        LogicExpression *ll = new LogicConstant(c.first.first, type.first,
                                                type.second, cn->getMaxTime());
        LogicExpression *rl = new LogicConstant(c.first.second, type.first,
                                                type.second, cn->getMaxTime());
        LogicExpression *l1 = copy(*cn->get()._le);
        LogicExpression *l2 = copy(*cn->get()._le);
        ret.push_back(std::make_pair(makeExpression<PropositionAnd>(
                                         makeExpression<LogicGreaterEq>(l1, ll),
                                         makeExpression<LogicLessEq>(l2, rl)),
                                     c.second));
      }
      if (cn->_clsOps.count(ClsOp::GE)) {
        LogicExpression *l1 = copy(*cn->get()._le);
        LogicExpression *ll = new LogicConstant(c.first.first, type.first,
                                                type.second, cn->getMaxTime());
        ret.push_back(
            std::make_pair(makeExpression<LogicGreaterEq>(l1, ll), c.second));
      }
      if (cn->_clsOps.count(ClsOp::LE)) {
        LogicExpression *l2 = copy(*cn->get()._le);
        LogicExpression *rl = new LogicConstant(c.first.second, type.first,
                                                type.second, cn->getMaxTime());
        ret.push_back(
            std::make_pair(makeExpression<LogicLessEq>(l2, rl), c.second));
      }
    } else {
      if (cn->_clsOps.count(ClsOp::E)) {
        LogicExpression *lc = new LogicConstant(c.first.first, type.first,
                                                type.second, cn->getMaxTime());
        LogicExpression *le = copy(*cn->get()._le);
        ret.push_back(
            std::make_pair(makeExpression<LogicEq>(le, lc), c.second));
      }
    }
  }
  return ret;
}

template <typename T>
std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>>
makeNumericRange(
    std::vector<std::pair<std::pair<T, T>, std::pair<size_t, size_t>>>
        &clusters,
    std::pair<VarType, T> type, CachedAllNumeric *cn) {

  std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> ret;
  for (auto &c : clusters) {
    if (c.first.first != c.first.second) {
      if (cn->_clsOps.count(ClsOp::Range)) {
        NumericExpression *ll = new NumericConstant(
            c.first.first, type.first, type.second, cn->getMaxTime());
        NumericExpression *rl = new NumericConstant(
            c.first.second, type.first, type.second, cn->getMaxTime());
        NumericExpression *l1 = copy(*cn->get()._ne);
        NumericExpression *l2 = copy(*cn->get()._ne);
        ret.push_back(
            std::make_pair(makeExpression<PropositionAnd>(
                               makeExpression<NumericGreaterEq>(l1, ll),
                               makeExpression<NumericLessEq>(l2, rl)),
                           c.second));
      }
      if (cn->_clsOps.count(ClsOp::GE)) {
        NumericExpression *le1 = copy(*cn->get()._ne);
        NumericExpression *ll = new NumericConstant(
            c.first.first, type.first, type.second, cn->getMaxTime());
        ret.push_back(std::make_pair(makeExpression<NumericGreaterEq>(le1, ll),
                                     c.second));

        NumericExpression *le2 = copy(*cn->get()._ne);
        NumericExpression *rl = new NumericConstant(
            c.first.second, type.first, type.second, cn->getMaxTime());
        ret.push_back(std::make_pair(makeExpression<NumericGreaterEq>(le2, rl),
                                     c.second));
      }
      if (cn->_clsOps.count(ClsOp::LE)) {

        NumericExpression *ge1 = copy(*cn->get()._ne);
        NumericExpression *ll = new NumericConstant(
            c.first.first, type.first, type.second, cn->getMaxTime());
        ret.push_back(
            std::make_pair(makeExpression<NumericLessEq>(ge1, ll), c.second));

        NumericExpression *ge2 = copy(*cn->get()._ne);
        NumericExpression *rl = new NumericConstant(
            c.first.second, type.first, type.second, cn->getMaxTime());
        ret.push_back(
            std::make_pair(makeExpression<NumericLessEq>(ge2, rl), c.second));
      }
    } else {
      if (cn->_clsOps.count(ClsOp::E)) {
        NumericExpression *lc = new NumericConstant(
            c.first.first, type.first, type.second, cn->getMaxTime());
        NumericExpression *le = copy(*cn->get()._ne);
        ret.push_back(
            std::make_pair(makeExpression<NumericEq>(le, lc), c.second));
      }
    }
  }
  return ret;
}

template <typename T>
std::vector<Proposition *> inline makeLogicRange1D(
    std::vector<std::pair<T, T>> &clusters, std::pair<VarType, T> type,
    CachedAllNumeric *cn) {

  std::vector<Proposition *> ret;
  for (auto &c : clusters) {
    if (c.first != c.second) {
      if (cn->_clsOps.count(ClsOp::Range)) {
        LogicExpression *ll = new LogicConstant(c.first, type.first,
                                                type.second, cn->getMaxTime());
        LogicExpression *rl = new LogicConstant(c.second, type.first,
                                                type.second, cn->getMaxTime());
        LogicExpression *l1 = copy(*cn->get()._le);
        LogicExpression *l2 = copy(*cn->get()._le);
        ret.push_back(makeExpression<PropositionAnd>(
            makeExpression<LogicGreaterEq>(l1, ll),
            makeExpression<LogicLessEq>(l2, rl)));
      }
      if (cn->_clsOps.count(ClsOp::GE)) {
        LogicExpression *l1 = copy(*cn->get()._le);
        LogicExpression *ll = new LogicConstant(c.first, type.first,
                                                type.second, cn->getMaxTime());
        ret.push_back(makeExpression<LogicGreaterEq>(l1, ll));
      }
      if (cn->_clsOps.count(ClsOp::LE)) {
        LogicExpression *l2 = copy(*cn->get()._le);
        LogicExpression *rl = new LogicConstant(c.second, type.first,
                                                type.second, cn->getMaxTime());
        ret.push_back(makeExpression<LogicLessEq>(l2, rl));
      }
    } else {
      if (cn->_clsOps.count(ClsOp::E)) {
        LogicExpression *lc = new LogicConstant(c.first, type.first,
                                                type.second, cn->getMaxTime());
        LogicExpression *le = copy(*cn->get()._le);
        ret.push_back(makeExpression<LogicEq>(le, lc));
      }
    }
  }
  return ret;
}

template <typename T>
std::vector<Proposition *> inline makeNumericRange1D(
    std::vector<std::pair<T, T>> &clusters, std::pair<VarType, T> type,
    CachedAllNumeric *cn) {

  std::vector<Proposition *> ret;
  for (auto &c : clusters) {
    if (c.first != c.second) {
      if (cn->_clsOps.count(ClsOp::Range)) {
        NumericExpression *ll = new NumericConstant(
            c.first, type.first, type.second, cn->getMaxTime());
        NumericExpression *rl = new NumericConstant(
            c.second, type.first, type.second, cn->getMaxTime());
        NumericExpression *l1 = copy(*cn->get()._ne);
        NumericExpression *l2 = copy(*cn->get()._ne);
        ret.push_back(makeExpression<PropositionAnd>(
            makeExpression<NumericGreaterEq>(l1, ll),
            makeExpression<NumericLessEq>(l2, rl)));
      }
      if (cn->_clsOps.count(ClsOp::GE)) {
        NumericExpression *l1 = copy(*cn->get()._ne);
        NumericExpression *ll = new NumericConstant(
            c.first, type.first, type.second, cn->getMaxTime());
        ret.push_back(makeExpression<NumericGreaterEq>(l1, ll));
      }
      if (cn->_clsOps.count(ClsOp::LE)) {
        NumericExpression *l2 = copy(*cn->get()._ne);
        NumericExpression *rl = new NumericConstant(
            c.second, type.first, type.second, cn->getMaxTime());
        ret.push_back(makeExpression<NumericLessEq>(l2, rl));
      }
    } else {
      if (cn->_clsOps.count(ClsOp::E)) {
        NumericExpression *lc = new NumericConstant(
            c.first, type.first, type.second, cn->getMaxTime());
        NumericExpression *le = copy(*cn->get()._ne);
        ret.push_back(makeExpression<NumericEq>(le, lc));
      }
    }
  }
  return ret;
}

template <typename T>
std::vector<std::pair<std::pair<T, T>, std::pair<size_t, size_t>>>
clsElbow(std::vector<std::pair<T, T>> &elements, double clsEffort,
         const std::string &numericName) {
  std::vector<std::pair<std::pair<T, T>, std::pair<size_t, size_t>>> clusters;
  if (clc::clsAlg == "kmeans") {
    clusters = kmeansElbowStl<T>(elements, 20, clsEffort, 0, numericName);
  }
  return clusters;
}

std::vector<Proposition *> genPropsThroughClustering1D(std::vector<size_t> &ivs,
                                                       CachedAllNumeric *cn,
                                                       size_t max_length) {

  std::vector<Proposition *> ret;
  std::pair<VarType, size_t> type = cn->getType();

  if (cn->getType().first == VarType::Numeric) {
    if (cn->getType().second == 32) {
      std::vector<float> elements;
      for (auto &iv : ivs) {
        elements.push_back(cn->evaluate(iv)._f);
      }
      auto clusters = kmeansElbow<float>(elements, 20, cn->_clsEffort, 0);
      return makeNumericRange1D<float>(clusters, type, cn);
    } else {
      std::vector<double> elements;
      for (auto &iv : ivs) {
        elements.push_back(cn->evaluate(iv)._d);
      }
      auto clusters = kmeansElbow<double>(elements, 20, cn->_clsEffort, 0);
      ret = makeNumericRange1D<double>(clusters, type, cn);
    }
  } else if (cn->getType().first == VarType::SLogic) {
    std::vector<SLogic> elements;
    for (auto &iv : ivs) {
      elements.push_back(cn->evaluate(iv)._s);
    }
    auto clusters = kmeansElbow<SLogic>(elements, 20, cn->_clsEffort, 0);
    ret = makeLogicRange1D<SLogic>(clusters, type, cn);
  } else if (cn->getType().first == VarType::ULogic) {
    std::vector<SLogic> elements;
    for (auto &iv : ivs) {
      elements.push_back(cn->evaluate(iv)._u);
    }
    std::vector<std::pair<SLogic, SLogic>> clusters =
        kmeansElbow<SLogic>(elements, 20, cn->_clsEffort, 0);
    ret = makeLogicRange1D<SLogic>(clusters, type, cn);
  } else {
    messageError("Unknown type in CachedAllNumeric");
  }

  //  debug
  //  for (auto &p : ret) {
  //    std::cout << prop2String(*p)<< "\n";
  //  }
  return ret;
}

std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>>
genPropsThroughClustering(
    std::vector<std::pair<CachedAllNumeric::EvalRet, size_t>> &ivs,
    CachedAllNumeric *cn, size_t max_length) {

  std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> ret;
  std::pair<VarType, size_t> type = cn->getType();

  if (cn->getType().first == VarType::Numeric) {
    if (cn->getType().second == 32) {
      std::vector<std::pair<float, float>> elements;
      for (auto &iv : ivs) {
        elements.push_back(std::make_pair(iv.first._f, (float)iv.second));
      }
      auto clusters =
          clsElbow<float>(elements, cn->_clsEffort, allNum2String(*cn));
      ret = makeNumericRange<float>(clusters, type, cn);
    } else {
      std::vector<std::pair<double, double>> elements;
      for (auto &iv : ivs) {
        elements.push_back(std::make_pair(iv.first._d, (double)iv.second));
      }
      auto clusters =
          clsElbow<double>(elements, cn->_clsEffort, allNum2String(*cn));
      ret = makeNumericRange<double>(clusters, type, cn);
    }
  } else if (cn->getType().first == VarType::SLogic) {
    std::vector<std::pair<SLogic, SLogic>> elements;
    for (auto &iv : ivs) {
      elements.push_back(std::make_pair(iv.first._s, (SLogic)iv.second));
    }
    auto clusters =
        clsElbow<SLogic>(elements, cn->_clsEffort, allNum2String(*cn));
    ret = makeLogicRange<SLogic>(clusters, type, cn);
  } else if (cn->getType().first == VarType::ULogic) {
    std::vector<std::pair<SLogic, SLogic>> elements;
    for (auto &iv : ivs) {
      elements.push_back(std::make_pair(iv.first._u, (SLogic)iv.second));
    }
    std::vector<std::pair<std::pair<SLogic, SLogic>, std::pair<size_t, size_t>>>
        clusters =
            clsElbow<SLogic>(elements, cn->_clsEffort, allNum2String(*cn));
    ret = makeLogicRange<SLogic>(clusters, type, cn);
  } else {
    messageError("Unknown type in CachedAllNumeric");
  }

  //  debug
  //std::cout << "Clustered:" << "\n";
  //  for (auto &[p,inter] : ret) {
  //  std::cout << prop2String(*p) << "Interval: " <<inter.first << " , " << inter.second <<std::endl;
  //  }
  return ret;
}
} // namespace slam
