#include "Semaphore.hh"
#include "Templace.hh"
#include "colors.hh"
#include "globals.hh"
#include "message.hh"
#include "minerUtils.hh"

#include <algorithm>
#include <math.h>
#include <mutex.h>
#include <sstream>
#include <sys/wait.h>
#include <thread>
#include <utility>


namespace harm{
    Template::Template(Hstring &templateFormula, harm::Trace *trace,
                   DTLimits limits)
    : _templateFormula(templateFormula), _buildTemplateFormula(templateFormula),
      _max_length(trace->getLength()), _limits(limits), _trace(trace) {

  build();
}

Template::Template(const Template &original) {
  _templateFormula = original._buildTemplateFormula;
  _trace = original._trace;
  for (auto &s : _templateFormula) {
    //we need to reinizializes/copy all the propositions in the templateFormula to the new copy of the template, two instances of the same template should not have overlapping memory
    if (s._pp != nullptr) {
      if (s._t == Hstring::Stype::Inst) {
        s._pp = new Proposition *(new CachedProposition(copy(**s._pp)));
      } else {
        s._pp = new Proposition *(*s._pp);
      }
    }
  }
  _buildTemplateFormula = _templateFormula;
  _max_length = original._max_length;
  _limits = original._limits;
  _check = original._check;

  //rebuild the template
  build();

  //shallow copy, need to configure and copy the data
  _pg = original._pg;

  //only to bring _pg to the starting point, no permutations generated here
  genPermutations(original._aProps, original._cProps, original._acProps);

  //if the original contains permutations we simply copy the permutation matrix to _pg
  if (original._pg._perms != nullptr) {
    _pg._perms = copy_matrix(original._pg._perms, original._pg._size.first,
                             original._pg._size.second);
  }
}

Template::~Template() {

  if (_dtOp.second != nullptr) {
    //if the template uses a dt operator, the responsability of freeing _ant falls on the dt operator
    delete _dtOp.second;
  } else {
    delete _ant;
  }

  delete _con;

  delete[] _antCachedValues;
  delete[] _conCachedValues;

  for (size_t i = 0; i < l1Constants::MAX_THREADS; i++) {
    delete[] _cachedValuesP[i];
  }
  delete[] _cachedValuesP;

  if (_applyDynamicShift) {
    delete[] _dynamicShiftCachedValues;
    for (size_t i = 0; i < l1Constants::MAX_THREADS; i++) {
      delete[] _cachedDynShiftsP[i];
    }
    delete[] _cachedDynShiftsP;
  }

  // inst props are used only in a specific template: must be deleted in all instances of a template
  for (auto &ph_pp : _iToProp) {
    delete *ph_pp.second;
  }

  for (auto &ph_pp : _tokenToProp) {
    delete ph_pp.second;
  }
}
    
}; //namespace harm 
