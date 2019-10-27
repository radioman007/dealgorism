#include "simplegene.h"

SimpleGene::SimpleGene()
{
value = 1;
mutationForce = 0.1;
}

SimpleGene::SimpleGene(double val):Gene(val)
{
    mutationForce = 0.1;
}

SimpleGene::SimpleGene(double val, double force):Gene(val), mutationForce(force) {}

// устанавливаем новое значение value
// умножаем value на случаеное число от -1 до 1 и на силу матации
void SimpleGene::mutate()
{
srand(time(NULL));
value *= mutationForce * ((rand()%100)/((double)50)-1);
}


