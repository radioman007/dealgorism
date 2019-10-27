#include <iostream>
using namespace std;
#include <vector>
#include "simplegene.h"
int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;


    vector<SimpleGene> genes;
    genes.push_back(SimpleGene(1, 5));

    for(int i = 0; i<100; i++)
    {
        cout<<genes[0].getValueWithMutate()<<endl;
    }
    return 0;
}
