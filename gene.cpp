#include "gene.h"

Gene::Gene(double val)
{
    value = val;
}

double Gene::getValue() const
{
    return value;
}

void Gene::setValue(double val)
{
    value = val;
}

double Gene::getValueWithMutate()
{
    this->mutate();
    return this->getValue();
}

