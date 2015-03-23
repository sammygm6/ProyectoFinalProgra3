#include "gold.h"

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

gold::gold(string nombre,string contrasena,string id,int edad)
    :cliente(nombre,contrasena,id,edad),descuento(0.15),expiracion(10){

}

gold::gold(const gold& other)
    :cliente(other),descuento(0.15),expiracion(10){

}

gold::~gold(){

}

string gold::toString()const{
    stringstream ss;
    ss << cliente::toString();
    return ss.str();
}
double gold::getDescuento(double precio)const{
    double ret = descuento * precio;
    return precio - ret;
}
