#include "juego.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

juego::juego(string nombre,double precio,string clasificacion,string tipo)
    :nombre(nombre),precio(precio),clasificacion(clasificacion),tipo(tipo){

}

juego::juego(const juego& other)
    :nombre(other.nombre),precio(other.precio),clasificacion(other.clasificacion),tipo(other.tipo){

}

juego::~juego(){

}

string juego::toString()const{
    stringstream ss;
    ss << "Nombre: " << nombre;
    return ss.str();
}
string juego::getNombre()const{
    return nombre;
}
double juego::getPrecio()const{
    return precio;
}
string juego::getClasificacion()const{
    return clasificacion;
}
string juego::getTipo()const{
    return tipo;
}
void juego::setNombre(string nombre){
    this->nombre = nombre;
}

void juego::setPrecio(double precio){
    this->precio = precio;
}

void juego::setClasificacion(string clasificacion){
    this->clasificacion = clasificacion;
}

void juego::setTipo(string tipo){
    this->tipo = tipo;
}
