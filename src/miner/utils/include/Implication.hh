#pragma once

#include"TemporalExp.hh"

namespace harm{

    class Implication: public TemporalExp{

        public:
            Implication(std::vector<TemporalExp *> ant,std::vector<TemporalExp *> con);

            ~Implication();

            Trinary evaluate(size_t time);

        private:

            std::vector<TemporalExp *> _ant;
            std::vector<TemporalExp *> _con;

    }
};