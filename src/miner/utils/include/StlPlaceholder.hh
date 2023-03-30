#pragma once 

#include"TemporalExp.hh"

namespace harm{

    class StlPlaceholder: public TemporalExp{
        public:
            StlPlaceholder(Proposition ** prop);

            ~StlPlaceholder();

            Trinary evaluate(size_t time) override;

        private:

            Proposition ** _prop;
    };

};