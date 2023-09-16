#pragma once
#include "DTLimits.hh"
#include "Trace.hh"

namespace slam {
class Template;
}

namespace hparser {
void addTypeToTemplate(std::string &formula,
                       std::vector<slam::VarDeclaration> varDeclarations);

slam::Template *parseTemplate(std::string formula, slam::Trace *trace,
                              const std::string &language = "stl",
                              const slam::DTLimits &limits = slam::DTLimits(),
                              bool useCache = true);
} // namespace hparser
