#pragma once

#include"TemporalExp.hh"
#include<vector>

namespace harm{

    class StlImplication: public TemporalExp{

    private:
        std::vector<TemporalExp *> _ant;
        std::vector<TemporalExp *> _con;


    public:
        StlImplication(std::vector<TemporalExp *> ant,std::vector<TemporalExp *> con);

        ~StlImplication()=default;

        Trinary evaluate(size_t time);

   
    };
}//namespace harm