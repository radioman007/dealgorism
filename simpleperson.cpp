#include "simpleperson.h"

std::vector<Gene*> SimplePerson::getDNK() const
{
    return DNK;
}

void SimplePerson::setDNK(const std::vector<Gene*> &value)
{
    DNK = value;
}

SimplePerson::SimplePerson()
{

}

SimplePerson::SimplePerson(std::vector<double> &geneArray)
{
    for(int i=0;i<geneArray.size();i++)
    {
        SimpleGene* newGene = new SimpleGene();
        newGene->setValue(geneArray[i]);
        DNK.push_back(newGene);
    }
}

SimplePerson::SimplePerson(vector<Gene*> genes)
{
    for(int i=0; i<genes.size(); i++)
    {
        DNK[i]->setValue(genes[i]->getValue());
    }
}

Person* SimplePerson::mutate(Person* A,Person* B)
{
    std::vector<Gene*> aDNK = A->getDNK();
    std::vector<Gene*> bDNK = B->getDNK();
    std::vector<double> newPerson;
    for (int i=0;i<DNK.size();i++)
    {
        double mutantGene = DNK[i]->mutate(aDNK[i],bDNK[i]);
        newPerson.push_back(mutantGene);
    }
    SimplePerson* mutantPerson = new SimplePerson(newPerson);
    return mutantPerson;
}

double SimplePerson::fitness()
{
    // решаем уравнение 100a^2+343b+c=7000
    double a = this->getDNK()[0]->getValue();
    double b = this->getDNK()[1]->getValue();
    double c = this->getDNK()[2]->getValue();
    double result = 100*a*a+343*b+c;
    return abs(7000-result);
}
