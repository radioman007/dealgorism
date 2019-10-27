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
    virtual void mutate();
    virtual ~Gene();
};

#endif // GENE_H