#pragma once 

#include"TemporalExp.hh"

namespace harm{

    class StlEventually: public TemporalExp{
        public:
            StlEventually(TemporalExp& operand);

            ~StlEventually();

            Trinary evaluate(size_t time) override;

            void setInterval(std::pair<size_t,size_t> intv);

        private:
            std::pair<size_t,size_t> _interval;

            TemporalExp * _operand;
    }

};