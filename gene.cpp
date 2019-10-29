#include "gene.h"

double Gene::getValue() const
{
    return value;
}

void Gene::setValue(double val)
{
    value = val;
}

Gene::Gene()
{
value =1;
}

Gene::Gene(double val)
{
    value = val;
}

Gene::~Gene()
{

}
