#pragma once

#include "Trinary.hh"
#include "exp.hh"

namespace harm{
    class TemporalExp{
        public:
        
            virtual ~TemporalExp(){}
            
            virtual Trinary evaluate(size_t time) = 0;

    };   
};
