#include "platinum.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

platinum::platinum(string nombre,string contrasena,string id,int edad,string tipo)
    :cliente(nombre,contrasena,id,edad,tipo),descuento(0.4){

}

platinum::platinum(const cliente& other)
    :cliente(other),descuento(0.4){

}

platinum::platinum(const platinum& other)
    :cliente(other),descuento(0.4){

}

platinum::~platinum(){

}

string platinum::toString()const{
    stringstream ss;
    ss << cliente::toString();
    return ss.str();
}
double platinum::getDescuento(double precio)const{
    return precio * descuento;
}
