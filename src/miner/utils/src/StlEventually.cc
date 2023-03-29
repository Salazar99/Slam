#include"StlEventually.hh"

namespace harm{

    StlEventually::StlEventually(TemporalExp& operand):_operand(operand);

    Trinary StlEventually::evaluate(size_t time){
        if(time < _interval.first)
            return Trinary::F;
        else if(time > _interval.second)
            return Trinary::U;
        else 
            return _operand->evaluate(time);
    }

    void setInterval(std::pair<size_t,size_t> intv){
        _interval = intv;
    }

};