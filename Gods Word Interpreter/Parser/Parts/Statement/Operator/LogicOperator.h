#ifndef __GWI_PARSER_PARTS_BLOCK__LOGIC_STATEMENT_H__
#define __GWI_PARSER_PARTS_BLOCK__LOGIC_STATEMENT_H__

#include "../../Type/DefualtTypes.h"

#include "BinaryOperator.h"
#include "UnaryOperator.h"

namespace GWI {
    class Logic {
    protected:
        static bool checkBoolean(const VariableP &var);
        static bool checkBoolean(std::initializer_list<const VariableP*> vars);
    };

    class OperatorAnd : public BinaryOperator, private Logic {
        virtual inline void execute(VariableP &left, VariableP &right, VariableP &result);
    };

    class OperatorOr : public BinaryOperator, private Logic {
        virtual inline void execute(VariableP &left, VariableP &right, VariableP &result);
    };

    class OperatorNot : public UnaryOperator, private Logic {
        virtual inline void execute(VariableP &val, VariableP &result);
    };
}
#endif