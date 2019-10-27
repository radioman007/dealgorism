#include "simplegene.h"

SimpleGene::SimpleGene()
{

}

SimpleGene::SimpleGene(double val):Gene(val)
{
    mutationForce = 0.1;
}

SimpleGene::SimpleGene(double val, double force):Gene(val)
{
    mutationForce = force;
}

double SimpleGene::mutate(SimpleGene aGene,SimpleGene bGene)// не известно че по агрументом и как он вообще работает
{
    double newValue = this->getValue()+mutationForce*(aGene.getValue()+bGene.getValue());
    return newValue;
}
