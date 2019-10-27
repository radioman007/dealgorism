#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person() {}
    virtual void crossover(Person* person)=0;// mb 3 argumenta
    virtual double fitness()=0;
    // virtual Phenotype getPhenotype()=0;
    virtual ~Person() {}
};
//
#endif // PERSON_H
