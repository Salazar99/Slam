#pragma once

#include "TemporalExp.hh"
#include "Trace.hh"

namespace harm {

class StlEventually : public TemporalExp {
public:
  StlEventually(TemporalExp *operand, std::pair<size_t, size_t> *interval,
                Trace *trace);

  virtual ~StlEventually();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;

  TemporalExp *getOperand() { return _operand; }

  virtual size_t size() override;

  void setInterval(std::pair<size_t, size_t> *intv);

  std::pair<size_t, size_t> *getInterval();

private:
  TemporalExp *_operand;
  std::pair<size_t, size_t> *_interval;
  Trace *_trace;
};

}; // namespace harm
