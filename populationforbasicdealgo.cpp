#include "populationforbasicdealgo.h"
#include <iostream>
#include <ctime>

PopulationForBasicDEAlgo::PopulationForBasicDEAlgo()
{

}

PopulationForBasicDEAlgo::PopulationForBasicDEAlgo(vector<vector<double>> genes)
{
    for (int i = 0; i < genes.size(); i++)
    {
        std::vector<double> newVector = genes[i];
        SimplePerson* newPerson = new SimplePerson(newVector);
        persons.push_back(*newPerson);
    }
}

double PopulationForBasicDEAlgo::hyposesisTesting()
{
    while(getFitness()<=150)
    {
        turn();
    }
    return getFitness();
}

void PopulationForBasicDEAlgo::turn()
{
    for (int i=0;i<persons.size();i++)
    {
        mutation(i);
    }
}

void PopulationForBasicDEAlgo::mutation(int personNum)
{
    std::vector<int> ABCPersonsNums = randomChoise(personNum);
    SimplePerson xPerson = persons[personNum];
    SimplePerson aPerson = persons[ABCPersonsNums[0]];
    SimplePerson bPerson = persons[ABCPersonsNums[1]];
    SimplePerson cPerson = persons[ABCPersonsNums[2]];
    SimplePerson* mutantPerson = cPerson.mutatePerson(aPerson,bPerson);
    crossover(xPerson,*mutantPerson);
}

void PopulationForBasicDEAlgo::crossover(SimplePerson &X,SimplePerson &mutant)
{
    std::vector<SimpleGene> xDNK = X.getDNK();
    std::vector<SimpleGene> mutantDNK = mutant.getDNK();
    std::vector<double> tDNK;
    srand( time( 0 ) );
    for (int i=0;i<xDNK.size();i++)
    {
        double P = rand()%1;
        if(P>=0.5)
        {
            tDNK.push_back(mutantDNK[i].getValue());
        }
        else
        {
            tDNK.push_back(xDNK[i].getValue());
        }
    }
    SimplePerson* tPerson = new SimplePerson(tDNK);
    if(tPerson->fitness()>X.fitness())
    {
        X.setDNK(tPerson->getDNK());
    }
}

double PopulationForBasicDEAlgo::getFitness()
{
    double sum=0;
    for (int i=0;i<persons.size();i++)
    {
        sum = sum+persons[i].fitness();
    }
    return sum;
}

std::vector<int> PopulationForBasicDEAlgo::randomChoise(int pesronNum)
{
    srand( time( 0 ) );
    bool itIs = false;
    int collisionNumber;
    std::vector<int> personsNums;
    while(personsNums.size()!=3)
    {
        int randNum = rand()%(persons.size()-1);
        while(pesronNum!=randNum)
        {
           randNum = rand()%(persons.size()-1);
        }

        if(personsNums.size()>0)
        {
            for (int j=0;j<personsNums.size();j++)
            {
                 if(personsNums[j]==randNum)
                 {
                     collisionNumber = j;
                     itIs = true;
                 }
            }
            if(itIs)
            {
                while(pesronNum!=randNum && collisionNumber!=randNum)
                {
                   randNum = rand()%(persons.size()-1);
                }
                itIs = false;
            }
        }
        personsNums.push_back(randNum);
    }
    return personsNums;
}

