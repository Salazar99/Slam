
#include "Hstring.hh"
#include "DTAndF.hh"
#include "StlEventually.hh"

Hstring::Hstring(std::string s, Stype t, std::pair<size_t,size_t> * intv)
    : _s(s), _t(t), _intv(intv),_offset(-1) {
  _append.push_back(*this);
}
Hstring::Hstring(std::string s, Stype t, harm::TemporalExp ** te)
    : _s(s), _t(t), _intv(nullptr),_te(te),_offset(-1) {
  _append.push_back(*this);
}

Hstring::Hstring() : _s(""), _t(Stype::Temp), _intv(nullptr),_te(nullptr),_offset(-1) {
  _append.push_back(*this);
}
Hstring Hstring::operator+(const Hstring &right) {
  auto left = *this;
  if (right._append.empty()) {
      //single char
    left._append.push_back(right);
  } else {
      //string
    for (const auto &i : right._append) {
      left._append.push_back(i);
    }
  }
  return left;
}
size_t Hstring::size() { return _append.size(); }

Hstring &Hstring::operator[](size_t i) { return _append[i]; }
bool Hstring::exists(std::string toFind) {
  for (auto &i : _append) {

    if (i._s == toFind) {
      return true;
    }
  }
  return false;
}

std::string Hstring::toColoredString(bool sub) {
    messageErrorIf(_append.empty(),"Attempted to print a char or an empty string");
  std::string ret = "";
  for (auto &e : _append) {
    switch (e._t) {
    case Stype::G:
      ret += GLOB(e._s);
      break;
    case Stype::Temp:
      ret += TEMP(e._s);
      break;
    case Stype::Ph:
      //FIXME Hstring no longer have a proposition pointer, must get prop from TemporalExp
      ret += VAR((sub ? prop2ColoredString(*((*e._te)->getItems().at(0))) : e._s));
      break;
    case Stype::DTAndF:
      //FIXME
      if ((*e._te)->getItems().empty()) {
        ret += BOOL("..F..");
      } else {
        std::vector<harm::TemporalExp *> tprops = (dynamic_cast<harm::TemporalAnd &>(**e._te)).getTempItems(); 
        size_t i = 0;
        for(auto tp : tprops){
          if(i != 0)
            ret += " && ";
          ret += "F[" + intv2String((dynamic_cast<harm::StlEventually *>(tp))->getInterval()) + "]" + prop2ColoredString(*(tp->getItems().at(0)));
          i++;
        }          
      }
      break;
    case Stype::Inst:
      //FIXME
      ret += prop2ColoredString(*((*e._te)->getItems().at(0)));
      break;
    case Stype::Intv:
      ret += e._s;
      break;
    case Stype::Imp:
      ret += TIMPL(e._s);
      break;
    default:;
    }
  }
  return ret;
}

std::string Hstring::intv2String(std::pair<size_t,size_t> * intv){
  std::string ret = std::to_string(intv->first) + "," + std::to_string(intv->second);
  return ret;
}

std::string Hstring::toString(bool sub) {
    messageErrorIf(_append.empty(),"Attempted to print a char or an empty string");

  std::string ret = "";
  for (auto &e : _append) {
    switch (e._t) {
    case Stype::G:
      ret += e._s;
      break;
    case Stype::Temp:
      ret += e._s;
      break;
    case Stype::Ph:
      ret += (sub ? prop2String(*((*e._te)->getItems().at(0))) : e._s);
      break;
    case Stype::DTAndF:
      //FIXME
      if ((*e._te)->getItems().empty()) {
        ret += "..F..";
      } else {
        std::vector<harm::TemporalExp *> tprops = (dynamic_cast<harm::TemporalAnd &>(**e._te)).getTempItems(); 
        size_t i = 0;
        for(auto tp : tprops){
          if(i != 0)
            ret += " && ";
          ret += "F[" + intv2String((dynamic_cast<harm::StlEventually *>(tp))->getInterval()) + "]" + prop2String(*(tp->getItems().at(0)));
          i++;
        }          
      }
      break;
    case Stype::Inst:
      ret += prop2String(*((*e._te)->getItems().at(0)));
      break;
    case Stype::Intv:
      ret += e._s;
      break;
    case Stype::Imp:
      ret += e._s;
      break;

    default:;
    }
  }
  return ret;
}

std::string Hstring::toSpotString() {

  std::string ret = "";
  for (auto &e : _append) {
    switch (e._t) {
    case Stype::G:
      ret += e._s;
      break;
    case Stype::Temp:
      ret += e._s;
      break;
    case Stype::Ph:
      ret += e._s;
      break;
    case Stype::DTAndF:
      ret += e._s;
      break;
    case Stype::Inst:
      ret += e._s;
      break;
    case Stype::Imp:
      ret += e._s;
      break;
    default:;
    }
  }
  return ret;
}

Hstring Hstring::getAnt() {
  Hstring ret;
  //i == 4: 0 1   2   3 4
  //        G [ x1,x2 ] ( ...
  size_t i = 4;
  while (_append[i]._t != Stype::Imp) {
    ret._append.push_back(_append[i++]);
  }
  return ret;
}
Hstring Hstring::getCon() {
  Hstring ret;
  size_t i = 1;
  while (_append[i++]._t != Stype::Imp)
    ;

  while (i < size() - 1) {
    ret._append.push_back(_append[i++]);
  }
  return ret;
}
Hstring Hstring::getImp() {
  size_t i = 0;
  while (_append[i++]._t != Stype::Imp)
    ;

  return _append[i - 1];
}
std::vector<Hstring>::iterator Hstring::begin() { return _append.begin(); }

std::vector<Hstring>::iterator Hstring::end() { return _append.end(); }

std::vector<Hstring>::reverse_iterator Hstring::rbegin() {
  return _append.rbegin();
}

std::vector<Hstring>::reverse_iterator Hstring::rend() {
  return _append.rend();
}
bool Hstring::isDT(const Hstring &e) {
  switch (e._t) {
  case Stype::DTAndF:
    return 1;
    break;
  default:
    return 0;
  }
}

std::vector<Hstring> Hstring::getDTOperands() {
  std::vector<Hstring> ret;
  for (auto &e : _append) {
    if (isDT(e)) {
      ret.push_back(e);
    }
  }
  return ret;
}

void Hstring::insert(std::vector<Hstring>::iterator where,
                     const Hstring &toInsert) {
  _append.insert(where, toInsert);
}
std::ostream &operator<<(std::ostream &os, const Hstring::Stype &t) {

  switch (t) {
  case Hstring::Stype::DTAndF:
    os << "DTAndF";
    break;
  case Hstring::Stype::G:
    os << "G";
    break;
  case Hstring::Stype::Temp:
    os << "Temp";
    break;
  case Hstring::Stype::Imp:
    os << "Imp";
    break;
  case Hstring::Stype::Inst:
    os << "Inst";
    break;
  case Hstring::Stype::Intv:
    os << "Intv";
    break;
  case Hstring::Stype::Ph:
    os << "Ph";
    break;
  }
  return os;
}
