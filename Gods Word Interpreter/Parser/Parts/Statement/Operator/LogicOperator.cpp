#include "LogicOperator.h"

using namespace std;
using namespace GWI;

bool Logic::checkBoolean(const VariableP &var) {
    return *var->type == *def_type::BOOLEAN;
}

bool Logic::checkBoolean(std::initializer_list<const VariableP*> vars) {
    for (const VariableP *v : vars) {
        if (!checkBoolean(*v))
            return false;
    }
    return true;
}

void OperatorAnd::execute(VariableP &left, VariableP &right, VariableP &result) {
    if (checkBoolean({ &left, &right, &result }))
        return;

    result->setValue((void*)(((bool)left->getValue()) && ((bool)(right->getValue()))));
}

void OperatorOr::execute(VariableP &left, VariableP &right, VariableP &result) {
    if (checkBoolean({ &left, &right, &result }))
        return;

    result->setValue((void*)(((bool)left->getValue()) || ((bool)(right->getValue()))));
}

void OperatorNot::execute(VariableP &val, VariableP &result) {
    if (checkBoolean({ &val, &result }))
        return;

    result->setValue((void*)(!((bool)val->getValue())));
}
