#pragma once

#include "colors.hh"
#include "exp.hh"
#include "TemporalExp.hh"

#include <string>
#include <vector>

class Hstring {
public:
  enum class Stype {
    Temp,
    Intv,
    Ph,
    Inst,
    Imp,
    DTAndF,
    G
  };

  Hstring(std::string s, Stype t, std::pair<size_t,size_t> * intv = nullptr);

  Hstring(std::string s, Stype t, harm::TemporalExp ** te = nullptr);
  
  Hstring();

  ~Hstring() = default;

  Hstring operator+(const Hstring &right);
  Hstring getAnt();
  Hstring getCon();
  Hstring getImp();
  size_t size();

  Hstring &operator[](size_t i);

  std::vector<Hstring>::iterator begin();
  std::vector<Hstring>::iterator end();
  std::vector<Hstring>::reverse_iterator rbegin();
  std::vector<Hstring>::reverse_iterator rend();
  void insert(std::vector<Hstring>::iterator where, const Hstring &toInsert);

  bool exists(std::string toFind);

  std::string toColoredString(bool sub = false);
  std::string intv2String(std::pair<size_t,size_t> * intv);
  std::string toString(bool sub = false);
  std::string toSpotString();

  std::vector<Hstring> getDTOperands();
  static bool isDT(const Hstring &e);

  std::string _s;
  Stype _t;
  std::pair<size_t,size_t> * _intv;
  harm::TemporalExp ** _te;
  int _offset;
  std::string _sep;

private:
  std::vector<Hstring> _append;
};
  std::ostream & operator<<(std::ostream &os,const Hstring::Stype &t);
