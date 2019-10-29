#ifndef POPULATIONFORBASICDEALGO_H
#define POPULATIONFORBASICDEALGO_H
#include "population.h"
#include "person.h"
#include "simpleperson.h"
#include <vector>
#include <iostream>
using namespace std;
class PopulationForBasicDEAlgo: public Population
{
private:
    std::vector<Person*> persons;
public:
    PopulationForBasicDEAlgo();
    PopulationForBasicDEAlgo(std::vector<std::vector<double>> &population);
    PopulationForBasicDEAlgo(vector<Person*> pers);
    double hyposesisTesting();//запускает проверку данной гипотезы
    void turn();// один виток эволюции (1 цикл алгоритма DE)
    void mutation(int personNum);//вызывает мутацию у всей популяции (вызывается в turn)
    void crossover(Person* X,Person* mutant);//вызывает спаривание особей (вызывается в turn)
    double getFitness();//мб массив массивов возвращает(но это не точно) (вызывается в turn в конце и возвращает что-то, это что-то должно вернутся из turn и сверится с Критерием Остановы (К.О.) если ок то больше метод turn не запустится)
    std::vector<int> randomChoise(int pesronNum);
};

#endif // POPULATIONFORBASICDEALGO_H
