#include"Implication.hh"

namespace harm{

    Implication:Implication(std::vector<TemporalExp *> ant,std::vector<TemporalExp *> con){
        _ant = ant;
        _con = con;
    };

    Implication::~Implication(){};

    Trinary evaluate(size_t time){
        Trinary ret = Trinary::F;
        for(auto p : _ant){
            //A subformula of the _ant is F -> the entire antecedent is F -> implication is true regardless of the con
            if(p->evaluate(time) == Trinary::F)
                return Trinary::T;
        }

        //if we are here, ant is T
        for(auto p: _con){
            //ant = T and con = F -> impl is false
            if(p->evaluate(time) == Trinary::F)
                return Trinary::F
        }
        //ant is T and con is T -> impl is T
        return Trinary::T;
    }

};