#ifndef SIMPLEPERSON_H
#define SIMPLEPERSON_H
#include "person.h"
#include "simplegene.h"
#include <vector>

class SimplePerson: public Person
{
private:
   std::vector<SimpleGene> DNK;
public:
    SimplePerson();
    SimplePerson(std::vector<double> &geneArray);
    SimplePerson* mutatePerson(SimplePerson &A, SimplePerson &B);
    void crossover(Person* person);
    double fitness();
    std::vector<SimpleGene> getDNK() const;
    void setDNK(const std::vector<SimpleGene> &value);
};

#endif // SIMPLEPERSON_H
