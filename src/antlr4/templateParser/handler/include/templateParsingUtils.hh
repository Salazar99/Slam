#pragma once
#include "DTLimits.hh"
#include "Trace.hh"

namespace harm {
class Template;
}

namespace hparser {
void addTypeToTemplate(std::string &formula,
                       std::vector<harm::VarDeclaration> varDeclarations);

harm::Template *parseTemplate(std::string formula, harm::Trace *trace,
                              const std::string &language = "stl",
                              const harm::DTLimits &limits = harm::DTLimits(),
                              bool useCache = true);
} // namespace hparser
