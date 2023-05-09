#pragma once

#include "VarType.hh"
#include "cConversion.hh"
#include "classes/atom/Atom.hh"
#include "classes/atom/CachedAllNumeric.hh"
#include "exp.hh"

std::ostream &operator<<(std::ostream &os, expression::Proposition &p);
std::string prop2String(expression::Proposition &p);
std::string num2String(expression::NumericExpression &n);
std::string log2String(expression::LogicExpression &l);
std::string prop2ColoredString(expression::Proposition &p);
std::string allNum2String(expression::CachedAllNumeric &all);
std::string temp2String(expression::TemporalExp &p, bool subPlaceholders = 0);

std::string temp2ColoredString(expression::TemporalExp &p,
                               bool subPlaceholders = 0);
expression::Proposition *copy(expression::Proposition &p);
expression::TemporalExp *copy(expression::TemporalExp &p) ;
expression::LogicExpression *copy(expression::LogicExpression &le);
expression::NumericExpression *copy(expression::NumericExpression &ne);

void sortPropositions(std::vector<expression::Proposition *> &props);
size_t prop2NumVars(expression::Proposition &p);
size_t getNumVariables(const std::vector<expression::Proposition *> &props);
size_t getRepetitions(const std::vector<expression::Proposition *> &props);
std::vector<std::pair<std::string, size_t>> getVars(expression::Proposition &p,
                                                    bool keepIndex = false);
