#include "gene.h"

double Gene::getValue() const
{
    return value;
}

void Gene::setValue(double val)
{
    value = val;
}

void Gene::mutate()
{

}

Gene::Gene()
{

}

Gene::Gene(double val)
{
    value = val;
}

Gene::~Gene()
{

}
