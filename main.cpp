#include <iostream>
#include "simplegene.h"
#include "simpleperson.h"
#include "populationforbasicdealgo.h"
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    srand( time(0));
    vector<vector<double>> vec = {{1,2,3},
                                  {54,534,3},
                                  {345,1243,65},
                                  {534,543,88},
                                  {12,54,77},
                                  {541,228,322},
                                 {312,22428,3232},
                                 {71,546,76},
                                 {89,6,3225}};
//    vector<Person*> pers;

//    for (int i=0; i<10; i++)
//    {
//    vector<Gene*> genes;
//    double random = (rand()%1000)-500.0;
//    genes.push_back(new SimpleGene(random, 1));
//    random = (rand()%1000)-500.0;
//    genes.push_back(new SimpleGene(random, 1));
//    random = (rand()%1000)-500.0;
//    genes.push_back(new SimpleGene(random, 1));
//    pers.push_back(new SimplePerson(genes));
//    }

    PopulationForBasicDEAlgo pop(vec);
    pop.hyposesisTesting();
    return 0;
}
