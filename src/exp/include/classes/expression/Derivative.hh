#pragma once

#include "classes/atom/Atom.hh"

namespace expression {

/// @brief Derivative declaration.
/// This class represents the bit selector operator
template <typename ET,typename RT> class Derivative : public RT {


  public:
    Derivative(ET *e, size_t shift);

    using ReturnType = typename std::conditional<std::is_same<RT, NumericExpression>::value, Numeric, ULogic>::type;
    /// @brief Copy constructor.
    Derivative(const Derivative &other) = delete;

    /// @brief Destructor.
    virtual ~Derivative();

    /// @brief Evaluate the expression in a given simulation time.
    /// @param time The simulation time
    /// @return The value of the expression
    ReturnType evaluate(size_t time) override;

    /// @brief Accepts a visitor to visit the current object.
    /// @param vis The visitor.
    void acceptVisitor(ExpVisitor &vis) override;

    /// @brief Return the expression of the next operator
    /// @return A reference to the expression.
    ET &getItem();

    /// @brief Assing operator
    Derivative &operator=(const Derivative &other) = delete;

    size_t getShift();


  private:
    ET *_e;
    size_t _shift=0;
};
using LogicDerivative = Derivative<LogicExpression,LogicExpression>;
using NumericDerivative = Derivative<NumericExpression,NumericExpression>;
using PropDerivative = Derivative<Proposition,LogicExpression>;

} // namespace oden

#include "Derivative.i.hh"
