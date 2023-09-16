#pragma once
#include "exp.hh"
#include "Trace.hh"

namespace hparser{
void addTypeToProposition(std::string &formula,
                          std::vector<exharm::VarDeclaration> varDeclarations) ;

expression::Proposition *parseProposition(std::string formula, exharm::Trace *trace);
expression::Proposition *parsePropositionAlreadyTyped(std::string formula, exharm::Trace *trace);
}
