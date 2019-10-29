#include "simplegene.h"

SimpleGene::SimpleGene()
{
this->setValue(1);
mutationForce = 1;
}

SimpleGene::SimpleGene(double val):Gene(val)
{
    mutationForce = 1;
}

SimpleGene::SimpleGene(double val, double force):Gene(val)
{
    mutationForce = force;
}

double SimpleGene::mutate(Gene* aGene,Gene* bGene)
{
    double newValue = this->getValue()+mutationForce*(aGene->getValue()-bGene->getValue());
    return newValue;
}
