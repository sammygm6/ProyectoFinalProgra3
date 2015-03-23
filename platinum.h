#ifndef PLATINUM_H
#define PLATINUM_H

#include "cliente.h"
#include <string>

using std::string;


class platinum : public cliente
{
    double descuento;
public:
    platinum(string,string,string,int);
    platinum(const platinum&);
    ~platinum();
    virtual string toString()const;
    virtual double getDescuento(double)const;
};

#endif // PLATINUM_H
