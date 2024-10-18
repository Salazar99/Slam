#pragma once

#include "exp.hh"
#include "expUtils/VarType.hh"
#include "message.hh"
#include <memory>
#include <string>
#include <unordered_map>

namespace slam {
class Template;
class Automaton;
class EdgeProposition;

/** \brief To print a ClsOp
   */
std::ostream &operator<<(std::ostream &os, ClsOp op);

std::pair<expression::VarType, size_t>
variableTypeFromString(const std::string &type, size_t size = 1);


std::vector<std::pair<expression::Proposition *,std::pair<size_t,size_t>>>
genPropsThroughClustering(std::vector<std::pair<expression::CachedAllNumeric::EvalRet,size_t>> &ivs , expression::CachedAllNumeric *cn, size_t max_length) ;

std::vector<expression::Proposition *> genPropsThroughClustering1D(std::vector<size_t> &ivs,
                                                     expression::CachedAllNumeric *cn,
                                                     size_t max_length);

} // namespace slam
