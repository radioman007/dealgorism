#ifndef GENE_H
#define GENE_H

class Gene
{
    protected:
    double value;
public:
    Gene() {}
    Gene(double val);
    double getValue() const;
    void setValue(double val);
    virtual void mutate() = 0;
    double getValueWithMutate();
    virtual ~Gene() {}
};

#endif // GENE_H
