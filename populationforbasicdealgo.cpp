#include "populationforbasicdealgo.h"
#include <iostream>
#include <ctime>

PopulationForBasicDEAlgo::PopulationForBasicDEAlgo()
{

}

PopulationForBasicDEAlgo::PopulationForBasicDEAlgo(std::vector<std::vector<double> > &population)
{
    for (int i=0;i<population.size();i++)
    {
        std::vector<double> newVector = population[i];
        SimplePerson* newPerson = new SimplePerson(newVector);
        persons.push_back(newPerson);
    }
}

PopulationForBasicDEAlgo::PopulationForBasicDEAlgo(vector<Person*> pers)
{
    for(int i=0; i<persons.size(); i++)
    {
    persons[i]->setDNK(pers[i]->getDNK());
    }
}

double PopulationForBasicDEAlgo::hyposesisTesting()
{
    while(getFitness()>1000)
    //for (int i = 0; i<10; i++)
    {
        cout<<"\nVECTORS:\n";
        for (int i=0;i<persons.size();i++)
        {
            cout<<i<<": "<<this->persons[i]->getDNK()[0]->getValue()<<"\t";
            cout<<this->persons[i]->getDNK()[1]->getValue()<<"\t";
            cout<<this->persons[i]->getDNK()[2]->getValue()<<endl;
        }
        turn();
    }
    return getFitness();
}

void PopulationForBasicDEAlgo::turn()
{
    cout<<"\nturn"<<endl;
    for (int i=0;i<persons.size();i++)
    {
        mutation(i);
    }
}

void PopulationForBasicDEAlgo::mutation(int personNum)
{
    std::vector<int> ABCPersonsNums = randomChoise(personNum);

    cout<<"ABCPersonsNums0:"<<ABCPersonsNums[0]<<endl;
    cout<<"ABCPersonsNums1:"<<ABCPersonsNums[1]<<endl;
    cout<<"ABCPersonsNums2:"<<ABCPersonsNums[2]<<endl;

    Person* mutantPerson = persons[ABCPersonsNums[2]]->mutate(persons[ABCPersonsNums[0]],persons[ABCPersonsNums[1]]);
    crossover(persons[personNum],mutantPerson);
}

void PopulationForBasicDEAlgo::crossover(Person* X,Person* mutant)
{
    std::vector<Gene*> xDNK = X->getDNK();
    std::vector<Gene*> mutantDNK = mutant->getDNK();
    std::vector<double> tDNK;
    for (int i=0;i<xDNK.size();i++)
    {
        double P = (rand()%100)/100.0;
        if(P>=0.3)
        {
            tDNK.push_back(mutantDNK[i]->getValue());
        }
        else
        {
            tDNK.push_back(xDNK[i]->getValue());
        }
    }
    SimplePerson* tPerson = new SimplePerson(tDNK);
    cout<<"MUTANT:\n"<<mutant->getDNK()[0]->getValue()<<"\t";
    cout<<mutant->getDNK()[1]->getValue()<<"\t";
    cout<<mutant->getDNK()[2]->getValue()<<"\t"<<endl;
    cout<<"TPERSON:\n";
    cout<<tPerson->getDNK()[0]->getValue()<<"\t";
    cout<<tPerson->getDNK()[1]->getValue()<<"\t";
    cout<<tPerson->getDNK()[2]->getValue()<<endl;
    cout<<"TPERSON_FIT: "<<tPerson->fitness()<<" X_FIT: "<<X->fitness()<<endl;
    if(tPerson->fitness()<X->fitness())
    {
        X->setDNK(tPerson->getDNK());
    }
}

double PopulationForBasicDEAlgo::getFitness()
{
    double sum=0;
    for (int i=0;i<persons.size();i++)
    {
        sum = sum+persons[i]->fitness();
    }
    cout<<"sum:"<<sum<<endl;
    return sum;
}

std::vector<int> PopulationForBasicDEAlgo::randomChoise(int pesronNum)
{

    std::vector<int> personsNums;
    int a = rand()%(persons.size()-1);
    int b = rand()%(persons.size()-1);
    int c = rand()%(persons.size()-1);

    while (personsNums.size()<1) {
    if (a!=b && a!=c && a!=pesronNum) {
        personsNums.push_back(a);
    } else {
    a = rand()%(persons.size()-1);
    }
    }
    while (personsNums.size()<2) {
    if (b!=a && b!=c && b!=pesronNum) {
        personsNums.push_back(b);
    } else {
    b = rand()%(persons.size()-1);
    }
    }

    while (personsNums.size()<3) {
    if (c!=a && c!=b && c!=pesronNum) {
        personsNums.push_back(c);
    } else {
    c = rand()%(persons.size()-1);
    }
    }
    return personsNums;
}
