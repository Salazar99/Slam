#pragma once 

#include"TemporalExp.hh"
#include"Template.hh"

namespace harm{

    class StlPlaceholder: public TemporalExp{
        public:
            StlPlaceholder(Proposition ** prop);

            ~StlPlaceholder() = default;

            Trinary evaluate(size_t time) override;

        private:

            Proposition ** _prop;
    };

};