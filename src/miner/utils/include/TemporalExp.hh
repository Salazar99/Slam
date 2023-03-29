#pragma once

#include "Trinary.hh"

namespace harm{
    class TemporalExp{
        public:
            TemporalExp() = default;
        
            ~TemporalExp();
            
            virtual Trinary evaluate(size_t time) = 0;

    }   
};