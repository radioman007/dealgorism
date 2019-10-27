#include "simpleperson.h"

std::vector<SimpleGene> SimplePerson::getDNK() const
{
    return DNK;
}

void SimplePerson::setDNK(const std::vector<SimpleGene> &value)
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
        SimpleGene newGene;
        newGene.setValue(geneArray[i]);
        DNK.push_back(newGene);
    }
}

SimplePerson* SimplePerson::mutatePerson(SimplePerson &A,SimplePerson &B)
{
    std::vector<SimpleGene> aDNK = A.getDNK();
    std::vector<SimpleGene> bDNK = B.getDNK();
    std::vector<double> newPerson;
    for (int i=0;i<DNK.size();i++)
    {
      // double mutantGene = DNK[i].mutate();
    //    newPerson.push_back(mutantGene);
    }
    SimplePerson* mutantPerson = new SimplePerson(newPerson);
    return mutantPerson;
}

void SimplePerson::crossover(Person *person)
{
    //sex
}

double SimplePerson::fitness()
{
    double sum=0,i;
    for (i=0;i<DNK.size();i++)
    {
        sum = sum+DNK[i].getValue();
    }
    return sum/DNK.size();
}
