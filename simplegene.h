#ifndef SIMPLEGENE_H
#define SIMPLEGENE_H
#include "gene.h"
#include <iostream>
using namespace std;

class SimpleGene: public Gene
{
private:
    double mutationForce;
public:
    SimpleGene();
    SimpleGene(double val);
    SimpleGene(double val, double force);
    double mutate(Gene* aGene,Gene* bGene);
};

#endif // SIMPLEGENE_H
