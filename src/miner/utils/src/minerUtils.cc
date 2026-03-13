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

/// @brief This function generates the propositions and corresponding intervals
/// @param clusters: vector of clusters, each cluster is a pair of (pair of values, pair of intervals)
/// @param type: type of the variable
/// @param cn: CachedAllNumeric to get the max time and the supported clsOps
/// @param own_interval: if false (..F..) first interval is always {0,0}, otherwise it contains the interval to be assigned to this proposition (..G.. case)
/// @return vector with Proposition, own_intv, intv_shift
template <typename T>
std::vector<std::pair<Proposition *, std::pair<std::pair<size_t, size_t>,std::pair<size_t, size_t>>>>
makeNumericRange(
    std::vector<std::pair<std::pair<T, T>, std::pair<size_t, size_t>>>
        &clusters,
    std::pair<VarType, T> type, CachedAllNumeric *cn, bool own_interval) {

  //retval
  std::vector<std::pair<Proposition *, std::pair<std::pair<size_t, size_t>,std::pair<size_t, size_t>>>> ret;
  std::pair<std::pair<size_t, size_t>,std::pair<size_t, size_t>> ret_intv;

  for (auto &c : clusters) {
    if (c.first.first != c.first.second) {
      if(own_interval){
      //Need to calculate own_intv
        size_t temp_dim = c.second.second - c.second.first + 1;
        std::pair<size_t,size_t> own_intv = std::make_pair(0, temp_dim -1);
        std::pair<size_t,size_t> shift = std::make_pair(own_intv.first + c.second.second, own_intv.second + c.second.first);
        ret_intv = std::make_pair(own_intv, shift);
      }else{
        //own_intv is 0 and shift is simply the c.second
        std::pair<size_t,size_t> own_intv = std::make_pair(0,0);
        std::pair<size_t,size_t> shift = c.second;
        ret_intv = std::make_pair(own_intv, shift);
      }

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
                           ret_intv));
      }
      if (cn->_clsOps.count(ClsOp::GE)) {
        NumericExpression *le1 = copy(*cn->get()._ne);
        NumericExpression *ll = new NumericConstant(
            c.first.first, type.first, type.second, cn->getMaxTime());
        ret.push_back(std::make_pair(makeExpression<NumericGreaterEq>(le1, ll),
                                     ret_intv));

        NumericExpression *le2 = copy(*cn->get()._ne);
        NumericExpression *rl = new NumericConstant(
            c.first.second, type.first, type.second, cn->getMaxTime());
        ret.push_back(std::make_pair(makeExpression<NumericGreaterEq>(le2, rl),
                                     ret_intv));
      }
      if (cn->_clsOps.count(ClsOp::LE)) {

        NumericExpression *ge1 = copy(*cn->get()._ne);
        NumericExpression *ll = new NumericConstant(
            c.first.first, type.first, type.second, cn->getMaxTime());
        ret.push_back(
            std::make_pair(makeExpression<NumericLessEq>(ge1, ll), ret_intv));

        NumericExpression *ge2 = copy(*cn->get()._ne);
        NumericExpression *rl = new NumericConstant(
            c.first.second, type.first, type.second, cn->getMaxTime());
        ret.push_back(
            std::make_pair(makeExpression<NumericLessEq>(ge2, rl), ret_intv));
      }
    } else {
      if (cn->_clsOps.count(ClsOp::E)) {
        NumericExpression *lc = new NumericConstant(
            c.first.first, type.first, type.second, cn->getMaxTime());
        NumericExpression *le = copy(*cn->get()._ne);
        ret.push_back(
            std::make_pair(makeExpression<NumericEq>(le, lc), ret_intv));
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

std::vector<std::pair<Proposition *, std::pair<std::pair<size_t, size_t>,std::pair<size_t, size_t>>>>
genPropsThroughClustering(
    std::vector<std::pair<CachedAllNumeric::EvalRet, size_t>> &ivs,
    CachedAllNumeric *cn, size_t max_length) {

  std::vector<std::pair<Proposition *, std::pair<std::pair<size_t, size_t>,std::pair<size_t, size_t>>>> ret;
  std::pair<VarType, size_t> type = cn->getType();

  if (type.first == VarType::Numeric) {
    if (type.second == 32) {
      std::vector<std::pair<float, float>> elements;
      for (auto &iv : ivs) {
        elements.push_back(std::make_pair(iv.first._f, (float)iv.second));
      }
      auto clusters =
          clsElbow<float>(elements, cn->_clsEffort, allNum2String(*cn));
      ret = makeNumericRange<float>(clusters, type, cn, false);
    } else {
      std::vector<std::pair<double, double>> elements;
      for (auto &iv : ivs) {
        elements.push_back(std::make_pair(iv.first._d, (double)iv.second));
      }
      auto clusters =
          clsElbow<double>(elements, cn->_clsEffort, allNum2String(*cn));
      ret = makeNumericRange<double>(clusters, type, cn, false);
    }
  } else if (type.first == VarType::SLogic) {
    messageError("SLogic type unsupported in this operation");
  } else if (type.first == VarType::ULogic) {
    messageError("ULogic type unsupported in operation");
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
//Hash function Szudzik's Pairing Function = b^2 + a
size_t hashCluster(const std::pair<size_t,size_t> &intv){
    return intv.second * intv.second + intv.first;
}

std::vector<std::pair<Proposition *, std::pair<std::pair<size_t, size_t>,std::pair<size_t, size_t>>>>
genPropsThroughClustering3D(
    std::vector<std::pair<std::pair<CachedAllNumeric::EvalRet, size_t>, size_t>> &ivs,
    CachedAllNumeric *cn, size_t max_length) {

  //return var
  std::vector<std::pair<Proposition *, std::pair<std::pair<size_t, size_t>,std::pair<size_t, size_t>>>> ret;
  
  std::pair<VarType, size_t> type = cn->getType();

  if (type.first == VarType::Numeric) {
    //We are in the Numeric float case
    if (type.second == 32) {
      //We need to perform clustering for each segment
      //Each element is a vector of pairs of a segment
      std::vector<std::vector<std::pair<float, float>>> elements;

      //Maps clusters that are present in each segment analyzed, contains list of numeric pairs and the temporal interval
      // Key: hash
      // Value: { Vector of points, {Cluster boundaries, Last seen segment ID} } 
      std::unordered_map<size_t, std::pair<std::pair<float, float>, std::pair<std::pair<size_t, size_t>, size_t>>> accumulation_map;
      //List of hashes with number of segments in which the cluster is present
      std::unordered_map<size_t, size_t> hashes_hits;


      //Group elements by segment
      for (auto &iv : ivs) {
        auto unpacked = iv.first;
        auto segment = iv.second;
         //to avoid segfaults
        if(segment >= elements.size()){
          elements.resize(segment + 1); // resize to accommodate the new segment index
        }
        elements[segment].push_back(std::make_pair(unpacked.first._f, (float)unpacked.second));
      }
  
      
      // 3. Process segments
      for (size_t i = 0; i < elements.size(); ++i) {
        //If segment is empty skip it (maybe we could just break, since if a segment is empty nothing will be kept)
        if (elements[i].empty()) continue;
        //Launch clustering for this segment
        auto c = clsElbow<float>(elements[i], cn->_clsEffort, allNum2String(*cn));
        //For each generated cluster
        for (auto &cluster : c) {
            //Hash cluster using its temporal interval
            size_t hash = hashCluster(cluster.second);
            // if(clc::debugCls){
            //   std::cout << "Segment " << i << ": Cluster with boundaries [" << cluster.first.first << " , " << cluster.first.second << "] and temporal interval [" << cluster.second.first << " , " << cluster.second.second << "] has hash " << hash << "\n";
            // }
            if (i == 0) {
                // First segment: Always add
                accumulation_map[hash].first.first = cluster.first.first;
                accumulation_map[hash].first.second = cluster.first.second;
                accumulation_map[hash].second.first = cluster.second;
                accumulation_map[hash].second.second = i; // last_seen_segment
            } else{
                auto it = accumulation_map.find(hash);
                if (it != accumulation_map.end()) {
                  // Subsequent segments: Update ONLY if it survived previous prunes
                  float minval = std::min(cluster.first.first, accumulation_map[hash].first.first);
                  it->second.first.first = minval;
                  float maxval = std::max(cluster.first.second, accumulation_map[hash].first.second);
                  it->second.first.second = maxval;
                  it->second.second.first = cluster.second;
                  //update last_seen
                  it->second.second.second = i;
                }
            }
        }  
        //Pruning after all clusters of the segment have been processed
        if (i > 0) {
          for (auto it = accumulation_map.begin(); it != accumulation_map.end(); ) {
            //if not seen in this segment then remove it 
            if (it->second.second.second != i) {
              it = accumulation_map.erase(it); // erase returns the next valid iterator
            } else {
              //otherwise skip
              ++it;
            }
          }
        } 
        // if(clc::debugCls){
        //     std::cout << "After segment " << i << ", surviving clusters: " << accumulation_map.size() << "\n";
        //     for (const auto &entry : accumulation_map) {
        //         const auto &cluster_info = entry.second;
        //         std::cout << "Cluster with hash " << entry.first 
        //                   << " has num boundaries [" << cluster_info.first.first 
        //                   << " , " << cluster_info.first.second 
        //                   << "]. Has temporal interval [" << cluster_info.second.first.first
        //                   << ", " << cluster_info.second.first.second
        //                   << "] and was last seen in segment " << cluster_info.second.second << "\n";
        //     }
        // }
      }

      //Merge clusters that have same temporal interval
      std::vector<std::pair<std::pair<float, float>, std::pair<size_t, size_t>>> clusters;
      for (auto &entry : accumulation_map) {
        auto tmp = std::make_pair(entry.second.first, entry.second.second.first);
        clusters.push_back(tmp);
      }

      ret = makeNumericRange<float>(clusters, type, cn, true);   

    } else {
      //double case
      //We need to perform clustering for each segment
      //Each element is a vector of pairs of a segment
      std::vector<std::vector<std::pair<double, double>>> elements;

      //Maps clusters that are present in each segment analyzed, contains list of numeric pairs and the temporal interval
      // Key: hash
      // Value: { Vector of points, {Cluster boundaries, Last seen segment ID} } 
      std::unordered_map<size_t, std::pair<std::pair<double, double>, std::pair<std::pair<size_t, size_t>, size_t>>> accumulation_map;
      //List of hashes with number of segments in which the cluster is present
      std::unordered_map<size_t, size_t> hashes_hits;


      //Group elements by segment
      for (auto &iv : ivs) {
        auto unpacked = iv.first;
        auto segment = iv.second;
         //to avoid segfaults
        if(segment >= elements.size()){
          elements.resize(segment + 1); // resize to accommodate the new segment index
        }
        elements[segment].push_back(std::make_pair(unpacked.first._f, (double)unpacked.second));
      }
  
      
      // 3. Process segments
      for (size_t i = 0; i < elements.size(); ++i) {
        //If segment is empty skip it (maybe we could just break, since if a segment is empty nothing will be kept)
        if (elements[i].empty()) continue;
        //Launch clustering for this segment
        auto c = clsElbow<double>(elements[i], cn->_clsEffort, allNum2String(*cn));
        //For each generated cluster
        for (auto &cluster : c) {
            //Hash cluster using its temporal interval
            size_t hash = hashCluster(cluster.second);
            // if(clc::debugCls){
            //   std::cout << "Segment " << i << ": Cluster with boundaries [" << cluster.first.first << " , " << cluster.first.second << "] and temporal interval [" << cluster.second.first << " , " << cluster.second.second << "] has hash " << hash << "\n";
            // }
            if (i == 0) {
                // First segment: Always add
                accumulation_map[hash].first.first = cluster.first.first;
                accumulation_map[hash].first.second = cluster.first.second;
                accumulation_map[hash].second.first = cluster.second;
                accumulation_map[hash].second.second = i; // last_seen_segment
            } else{
                auto it = accumulation_map.find(hash);
                if (it != accumulation_map.end()) {
                  // Subsequent segments: Update ONLY if it survived previous prunes
                  double minval = std::min(cluster.first.first, accumulation_map[hash].first.first);
                  it->second.first.first = minval;
                  double maxval = std::max(cluster.first.second, accumulation_map[hash].first.second);
                  it->second.first.second = maxval;
                  it->second.second.first = cluster.second;
                  //update last_seen
                  it->second.second.second = i;
                }
            }
        }  
        //Pruning after all clusters of the segment have been processed
        if (i > 0) {
          for (auto it = accumulation_map.begin(); it != accumulation_map.end(); ) {
            //if not seen in this segment then remove it 
            if (it->second.second.second != i) {
              it = accumulation_map.erase(it); // erase returns the next valid iterator
            } else {
              //otherwise skip
              ++it;
            }
          }
        } 
        // if(clc::debugCls){
        //     std::cout << "After segment " << i << ", surviving clusters: " << accumulation_map.size() << "\n";
        //     for (const auto &entry : accumulation_map) {
        //         const auto &cluster_info = entry.second;
        //         std::cout << "Cluster with hash " << entry.first 
        //                   << " has num boundaries [" << cluster_info.first.first 
        //                   << " , " << cluster_info.first.second 
        //                   << "]. Has temporal interval [" << cluster_info.second.first.first
        //                   << ", " << cluster_info.second.first.second
        //                   << "] and was last seen in segment " << cluster_info.second.second << "\n";
        //     }
        // }
      }

      //Merge clusters that have same temporal interval
      std::vector<std::pair<std::pair<double, double>, std::pair<size_t, size_t>>> clusters;
      for (auto &entry : accumulation_map) {
        auto tmp = std::make_pair(entry.second.first, entry.second.second.first);
        clusters.push_back(tmp);
      }

      ret = makeNumericRange<double>(clusters, type, cn, true);   
    }
  } else if (type.first == VarType::SLogic) {
    messageError("SLogic type unsupported for this type of operator");
  } else if (type.first == VarType::ULogic) {
    messageError("ULogic type unsupported for this type of operator");
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
