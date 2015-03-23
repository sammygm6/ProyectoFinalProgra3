#include "normal.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

normal::normal(string nombre,string contrasena,string id,int edad)
    :cliente(nombre,contrasena,id,edad),descuento(0.01){

}

normal::normal(const normal & other)
    :cliente(other),descuento(0.01){

}

normal::~normal(){

}

string normal::toString()const{
    stringstream ss;
    ss << cliente::toString();
    return ss.str();
}
double normal::getDescuento(double precio)const{
    double ret = descuento * precio;
    return precio - ret;
}
