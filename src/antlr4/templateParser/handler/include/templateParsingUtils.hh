#pragma once
#include "DTLimits.hh"
#include "Trace.hh"

namespace exharm {
class Template;
}

namespace hparser {
void addTypeToTemplate(std::string &formula,
                       std::vector<exharm::VarDeclaration> varDeclarations);

exharm::Template *parseTemplate(std::string formula, exharm::Trace *trace,
                              const std::string &language = "stl",
                              const exharm::DTLimits &limits = exharm::DTLimits(),
                              bool useCache = true);
} // namespace hparser
