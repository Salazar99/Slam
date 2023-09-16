#pragma once
#include "Trace.hh"
#include "Metric.hh"

namespace hparser{
void addTypeToMetric(std::string &formula,
                          std::vector<exharm::VarDeclaration> &varDeclarations) ;

exharm::Metric* parseMetric(const std::string &name, std::string &formula, exharm::Trace *trace) ;
}
