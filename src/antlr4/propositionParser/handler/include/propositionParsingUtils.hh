#pragma once
#include "exp.hh"
#include "Trace.hh"

namespace hparser{
void addTypeToProposition(std::string &formula,
                          std::vector<slam::VarDeclaration> varDeclarations) ;

expression::Proposition *parseProposition(std::string formula, slam::Trace *trace);
expression::Proposition *parsePropositionAlreadyTyped(std::string formula, slam::Trace *trace);
}
