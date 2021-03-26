#ifndef COMPILAX__COMMON__DREX__DREX_TOKEN_TYPE_HPP
#define COMPILAX__COMMON__DREX__DREX_TOKEN_TYPE_HPP

namespace compilax::drex
{

enum class DREXTokenType
{
    DirectiveDefine,
    DirectiveInclude,
    ConditionIf,
    ConditionElif,
    ConditionElse,
    ConditionEndif,
    OperatorDefined,
    OperatorNot,
    OperatorAnd,
    OperatorOr,
    OperatorBitwiseAnd,
    OperatorBitwiseOr,
    OperatorPlus,
    OperatorMinus,
    OperatorTimes,
    OperatorDivide,
    Macro,
    Comment,
    Text
};

}//namespace compilax::drex

#endif//COMPILAX__COMMON__DREX__DREX_TOKEN_TYPE_HPP