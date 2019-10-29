#ifndef GENE_H
#define GENE_H

class Gene
{
private:
    double value;
public:
    Gene();
    Gene(double val);
    double getValue() const;
    void setValue(double val);
    virtual double mutate(Gene* aGene,Gene* bGene) = 0;
    virtual ~Gene();
};

#endif // GENE_H
