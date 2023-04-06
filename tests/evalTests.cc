#include "CSVtraceReader.hh"
#include "Template.hh"
#include "Trace.hh"
#include "TraceReader.hh"
#include "VCDtraceReader.hh"
#include "globals.hh"
#include "templateParser.hh"
#include <gtest/gtest.h>

using namespace harm;
using namespace expression;

//FIXME: put new tests for harm-ex here
//To properly test need to implement interval declared by user, or interval mining.

class EvalTest : public ::testing::Test {
protected:
  EvalTest() {}

  ~EvalTest() override {}

  void SetUp() override {}

  void TearDown() override {
    delete _tr;
    delete _trace;
    delete _t;
    for (auto &[t, pp] : _tokenToProp) {
      delete *pp;
      delete pp;
    }
  
  }
//
//  Trinary evalAutomaton(size_t time, Automaton *root, size_t &dShift) const {
//    Automaton::Node *cn = root->_root;
//     visit the automaton by evaluating the edges (which are propositions)
//   
//    while (time < _max_length) {
//      for (const auto &edge : cn->_outEdges) {
//        // if "the current cn->_outEdges[i] is true at instant 'time'"
//        if (edge->_prop->evaluate(time)) {
//          if (edge->_toNode->_type == 0) {
//            dShift = time;
//            return Trinary::F;
//          } else if (edge->_toNode->_type == 1) {
//            // store the dynamic shift for the current evaluation
//            dShift = time;
//            return Trinary::T;
//          }
//
//          // go to the next state
//          cn = edge->_toNode;
//          break;
//        }
//      }
//      // each time we change state, time increases by 1
//      time++;
//    }
//    dShift = time;
//    return Trinary::U;
//  }

  void build(std::string tempStrAnt, std::string tempStrCon) {
    //Create the _impl object
    std::vector<harm::TemporalExp *> ant,con;
    std::pair<size_t **,size_t **> interval(_tokenToIntv.at("3"),_tokenToIntv.at("4"));

    ant.push_back(new StlEventually(new StlPlaceholder(_tokenToProp.at("v1")),interval));

    con.push_back(new StlPlaceholder(_tokenToProp.at("v2")));

    _impl = new harm::StlImplication(ant,con);
  }

  Trinary evaluate(size_t time) {return _impl->evaluate(time);}
  Trinary evaluate_ant(size_t time) { return _impl->evaluate_ant(time); }
  Trinary evaluate_con(size_t time) { return _impl->evaluate_con(time); }

  void check() {

    init();
    build(_tempStrAnt, _tempStrCon);

    for (size_t i = 0; i < _trace->getLength(); i++) {
      EXPECT_EQ(_t->evaluate_ant(i), evaluate_ant(i));
      EXPECT_EQ(_t->evaluate_con(i), evaluate_con(i));
      EXPECT_EQ(_t->evaluate(i), evaluate(i));
    }
  }

  void init() {

    _max_length = _trace->getLength();
    _t = hparser::parseTemplate("G[x1,x2](" + _tempStrAnt + _imp + _tempStrCon + ")",
                                _trace);
  }

public:
  TraceReader *_tr = nullptr;
  Trace *_trace = nullptr;
  size_t _max_length = 0;
  size_t _constShift = 0;
  StlImplication * _impl = nullptr;
  Template *_t = nullptr;
  std::unordered_map<std::string, expression::Proposition **> _tokenToProp;
  std::unordered_map<std::string, size_t **> _tokenToIntv;
  std::string _tempStrAnt = "";
  std::string _tempStrCon = "";
  std::string _imp = "";
};

TEST_F(EvalTest, t1) {
  _tr = new CSVtraceReader("../tests/input/EvalTest_t1.csv");
  _trace = _tr->readTrace();

  _tokenToProp["v1"] = new Proposition *(_trace->getBooleanVariable("v1"));
  _tokenToProp["v2"] = new Proposition *(_trace->getBooleanVariable("v2"));
  size_t * p1 = new size_t(1);
  size_t * p2 = new size_t(3);
  size_t **ptri1 = new size_t *(p1);
  size_t **ptri2 = new size_t *(p2);

  _tokenToIntv["1"] = ptri1; 
  _tokenToIntv["3"] = ptri2;

  _tempStrAnt = "F[1,3]v1";
  _tempStrCon = "v2";
  _imp = "->";

  check();
}
