#ifndef NORMAL_H
#define NORMAL_H
#include "cliente.h"
#include <string>

using std::string;

class normal : public cliente
{
    double descuento;
public:
    normal(string,string,string,int);
    normal(const normal&);
    ~normal();
    virtual string toString()const;
    virtual double getDescuento(double)const;
};

#endif // NORMAL_H
