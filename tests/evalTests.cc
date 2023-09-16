#include "CSVtraceReader.hh"
#include "Template.hh"
#include "Trace.hh"
#include "TraceReader.hh"
#include "VCDtraceReader.hh"
#include "globals.hh"
#include "templateParser.hh"
#include <gtest/gtest.h>
#include "propositionParser.hh"
#include "propositionParsingUtils.hh"

using namespace slam;
using namespace expression;
using namespace hparser;
//FIXME: put new tests for slam here
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
    //std::vector<expression::TemporalExp *> ant,con;
    //
    //ant.push_back(new Placeholder(_tokenToProp.at("v3")));
    //ant.push_back(new Eventually(new Placeholder(_tokenToProp.at("v1<5")),_tokenToIntv.at("1,3"),_trace));
    //
    //con.push_back(new Eventually(new Placeholder(_tokenToProp.at("v2")),_tokenToIntv.at("4,6"),_trace));
    //
    //_impl = new slam::Implication(ant,con);
  }

  Trinary evaluate(size_t time) {return _impl->evaluate(time);}
  Trinary evaluate_ant(size_t time) { return _impl->evaluate_ant(time); }
  Trinary evaluate_con(size_t time) { return _impl->evaluate_con(time); }

  void check() {

    init();
    build(_tempStrAnt, _tempStrCon);

    for (size_t i = 0; i < _trace->getLength(); i++) {
      std::cout<< "Time:" << i <<std::endl;
      EXPECT_EQ(_t->evaluate_ant(i), evaluate_ant(i));
      EXPECT_EQ(_t->evaluate_con(i), evaluate_con(i));
      EXPECT_EQ(_t->evaluate(i), evaluate(i));
      //std::cout<< "_t->evaluate_ant: " << _t->evaluate_ant(i) << ", ";
      //std::cout<< "evaluate_ant: " << evaluate_ant(i) << std::endl;
      //std::cout<< "_t->evaluate_con: " << _t->evaluate_con(i) << ", ";
      //std::cout<< "evaluate_con: " << evaluate_ant(i) << std::endl;
      std::cout << "t_->evaluate: " << _t->evaluate(i) << std::endl;
    }
  }

  void init() {

    _max_length = _trace->getLength();
    _t = hparser::parseTemplate("G[X1,X2](" + _tempStrAnt + _imp + _tempStrCon + ")",
                                _trace);
  }

public:
  TraceReader *_tr = nullptr;
  Trace *_trace = nullptr;
  size_t _max_length = 0;
  size_t _constShift = 0;
  Implication * _impl = nullptr;
  Template *_t = nullptr;
  std::unordered_map<std::string, expression::Proposition **> _tokenToProp;
  std::unordered_map<std::string, std::pair<size_t,size_t> *> _tokenToIntv;
  std::string _tempStrAnt = "";
  std::string _tempStrCon = "";
  std::string _imp = "";
};

TEST_F(EvalTest, t1) {
  /*
  _tr = new CSVtraceReader("/mnt/c/Users/danni/Desktop/Ex-harm/tests/input/EvalTest_t1.csv");
  _trace = _tr->readTrace();

  _tokenToProp["v1<5"] = new Proposition *(hparser::parsePropositionAlreadyTyped("<v1,logic(s,32)> > 5", _trace));
  _tokenToProp["v2"] = new Proposition *(_trace->getBooleanVariable("v2"));
  _tokenToProp["v3"] = new Proposition *(_trace->getBooleanVariable("v3"));
 
  std::pair<size_t,size_t> * ptri = new std::pair<size_t,size_t>(1,3); 
  _tokenToIntv.insert({"1,3",ptri}); 
  std::pair<size_t,size_t> * ptri1 = new std::pair<size_t,size_t>(4,6); 
  _tokenToIntv.insert({"4,6",ptri1});

  _tempStrAnt = "v3 && F[1,3]v1 > 5";
  _tempStrCon = "F[4,6]v2";
  _imp = "->";

  check();
  */
}
