#include "hypothesisgene.h"

HypothesisGene::HypothesisGene()
{
value = 1;
mutationForce = 0.1;
mutarionProbality = 0.5;
}

HypothesisGene::HypothesisGene(double val):Gene(val)
{
    mutationForce = 0.1;
    mutarionProbality = 0.5;
}

HypothesisGene::HypothesisGene(double val, double force):Gene(val), mutationForce(force)
{
    mutarionProbality = 0.5;
}

HypothesisGene::HypothesisGene(double val, double force, double probality):Gene(val),
    mutationForce(force),mutarionProbality(probality) {}

// устанавливаем новое значение value
// умножаем value на случаеное число от -1 до 1 и на силу матации
// НО при этом, если случ. число от 0 до 1 < вероятности, значит мутация срабатывает
void HypothesisGene::mutate()
{
    srand(time(NULL));
    if((rand()%100)*0.01 < mutarionProbality) {
        srand(time(NULL));
        value *= mutationForce * ((rand()%100)/((double)50)-1);
    }
}

