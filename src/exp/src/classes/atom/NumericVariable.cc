#include "visitors/ExpVisitor.hh"
#include "classes/atom/Variable.hh"

namespace expression {

NumericVariable::NumericVariable(Numeric *v, const std::string &name, VarType type, size_t size, size_t max_time) : Atom<Numeric>(type, size, max_time), _v(v), _name(name){
    // ntd
     }


Numeric NumericVariable::evaluate(size_t time) { return _v[time]; }

float NumericVariable::evaluate_robustness(size_t time) {
// In theory this is useless because the NumericVariable only needs to return its value
// but given that this its inherited from Atom we implement it.
    return static_cast<float>(_v[time]);
}

void NumericVariable::assign(size_t time, Numeric value) { _v[time] = value; }


void NumericVariable::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }

} 
