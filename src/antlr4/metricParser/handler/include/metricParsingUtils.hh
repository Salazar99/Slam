#pragma once
#include "Trace.hh"
#include "Metric.hh"

namespace hparser{
void addTypeToMetric(std::string &formula,
                          std::vector<slam::VarDeclaration> &varDeclarations) ;

slam::Metric* parseMetric(const std::string &name, std::string &formula, slam::Trace *trace) ;
}
