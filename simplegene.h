#ifndef SIMPLEGENE_H
#define SIMPLEGENE_H
#include "gene.h"

class SimpleGene: public Gene
{
private:
    double mutationForce;
public:
    SimpleGene();
    SimpleGene(double val);
    SimpleGene(double val, double force);
    double mutate(SimpleGene aGene,SimpleGene bGene);
};

#endif // SIMPLEGENE_H
