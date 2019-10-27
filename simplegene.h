#ifndef SIMPLEGENE_H
#define SIMPLEGENE_H
#include "gene.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
class SimpleGene: public Gene
{
private:
    double mutationForce;
public:
    SimpleGene();
    SimpleGene(double val);
    double getMutationForce() {return mutationForce;}
    void setMutationForce(double force) {mutationForce=force;}
    SimpleGene(double val, double force);
    void mutate();
    ~SimpleGene() {}
};

#endif // SIMPLEGENE_H
