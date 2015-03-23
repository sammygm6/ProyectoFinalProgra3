#ifndef GOLD_H
#define GOLD_H
#include "cliente.h"

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class gold : public cliente
{
    double descuento;
    int expiracion;
public:
    gold(string,string,string,int);
    gold(const gold&);
    ~gold();
    virtual string toString()const;
    virtual double getDescuento(double)const;

};

#endif // GOLD_H
