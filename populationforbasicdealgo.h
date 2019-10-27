#ifndef POPULATIONFORBASICDEALGO_H
#define POPULATIONFORBASICDEALGO_H
#include "population.h"
#include "simpleperson.h"
#include <vector>
using namespace std;
class PopulationForBasicDEAlgo: public Population
{
private:
    std::vector<SimplePerson> persons;
public:
    PopulationForBasicDEAlgo();
    PopulationForBasicDEAlgo(vector<vector<double>> genes);
    double hyposesisTesting();//запускает проверку данной гипотезы
    void turn();// один виток эволюции (1 цикл алгоритма DE)
    void mutation(int personNum);//вызывает мутацию у всей популяции (вызывается в turn)
    void crossover(SimplePerson &X,SimplePerson &mutant);//вызывает спаривание особей (вызывается в turn)
    double getFitness();//мб массив массивов возвращает(но это не точно) (вызывается в turn в конце и возвращает что-то, это что-то должно вернутся из turn и сверится с Критерием Остановы (К.О.) если ок то больше метод turn не запустится)
    vector<int> randomChoise(int pesronNum);
    ~PopulationForBasicDEAlgo() {}
};

#endif // POPULATIONFORBASICDEALGO_H
