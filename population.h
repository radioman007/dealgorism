#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include "person.h"

class Population
{
public:
    Population() {}
    virtual double hyposesisTesting()=0;
    virtual void turn()=0;
    virtual void mutation(int personNum)=0;
    virtual void crossover(Person &X,Person &mutant)=0;
    virtual double getFitness()=0;//мб массив массивов возвращает
    virtual std::vector<int> randomChoise(int pesronNum)=0;
    virtual void selection()=0;
    virtual ~Population() {}
};

#endif // POPULATION_H
