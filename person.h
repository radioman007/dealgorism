#ifndef PERSON_H
#define PERSON_H
#include <vector>
#include "gene.h"

class Person
{
public:
    Person();
    virtual Person* mutate(Person* A, Person* B) = 0;
    virtual double fitness() = 0;
    virtual std::vector<Gene*> getDNK() const = 0;
    virtual void setDNK(const std::vector<Gene*> &value)=0;
    virtual ~Person();
};

#endif // PERSON_H
