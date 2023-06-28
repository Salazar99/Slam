project(exp)

SET(EXP_SRCS
    src/classes/atom/CachedProposition.cc
    src/classes/atom/CachedAllNumeric.cc
    src/classes/atom/Constant.cc
    src/classes/atom/BooleanVariable.cc
    src/classes/atom/NumericVariable.cc
    src/classes/atom/LogicVariable.cc
    src/classes/expression/Expression.cc
    src/classes/expression/BitSelector.cc
    src/classes/expression/Derivative.cc
    src/classes/expression/TypeCast.cc
    #temporal
    src/classes/temporal/Eventually.cc
    src/classes/temporal/Implication.cc
    src/classes/temporal/TemporalInst.cc
    src/classes/temporal/Placeholder.cc
    src/classes/temporal/TemporalAnd.cc
    src/classes/temporal/TemporalOr.cc
    src/classes/temporal/TemporalNot.cc
    src/expUtils/expUtils.cc
    #visitors
    src/visitors/PrinterVisitor.cc
    src/visitors/CounterVisitor.cc
    src/visitors/ColoredPrinterVisitor.cc
    src/visitors/ExpVisitor.cc
    src/visitors/CopyVisitor.cc
    src/visitors/VarExtractVisitor.cc
    )



add_library(exp ${EXP_SRCS})

target_include_directories(exp PUBLIC include ../miner/utils/include/)
