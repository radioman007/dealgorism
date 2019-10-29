#ifndef SIMPLEPERSON_H
#define SIMPLEPERSON_H
#include "person.h"
#include <vector>
#include <math.h>
#include "gene.h"
#include "simplegene.h"
using namespace std;

class SimplePerson: public Person
{
private:
    std::vector<Gene*> DNK;
public:
    SimplePerson();
    SimplePerson(std::vector<double> &geneArray);
    SimplePerson(vector<Gene*> genes);
    Person* mutate(Person* A, Person* B);
    double fitness();
    std::vector<Gene*> getDNK() const;
    void setDNK(const std::vector<Gene*> &value);
};

#endif // SIMPLEPERSON_H
