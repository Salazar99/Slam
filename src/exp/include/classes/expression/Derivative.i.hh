namespace expression {

template <typename ET,typename RT>
Derivative<ET,RT>::Derivative(ET *e,  size_t shift)
    : RT(e->getType().first,shift,e->getMaxTime()), _e(e), _shift(shift) {
  // ntd
}

template <typename ET,typename RT> Derivative<ET,RT>::~Derivative() { delete _e; }

template <typename ET,typename RT> ET &Derivative<ET,RT>::getItem() { return *_e; }

template <typename ET,typename RT>
    size_t Derivative<ET,RT>::getShift(){
        return _shift;
    }

} // namespace oden
