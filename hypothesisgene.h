#ifndef HYPOTHESISGENE_H
#define HYPOTHESISGENE_H
#include "gene.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class HypothesisGene : public Gene
{
private:
    double mutationForce;
    double mutarionProbality;
public:
    HypothesisGene();
    HypothesisGene(double val);
    HypothesisGene(double val, double force);
    HypothesisGene(double val, double force, double probality);
    double getMutationForce() {return mutationForce;}
    void setMutationForce(double force) {mutationForce=force;}
    double getMutarionProbality() {return mutarionProbality;}
    void setMutarionProbality(double probality) {mutarionProbality=probality;}
    void mutate();
    ~HypothesisGene() {}
};



#endif // HYPOTHESISGENE_H
