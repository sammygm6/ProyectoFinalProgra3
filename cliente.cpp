#include "cliente.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

cliente::cliente(string nombre,string contrasena,string id,int edad,string tipo)
    :nombre(nombre),contrasena(contrasena),id(id),edad(edad),tipo(tipo),cliente_seleccionado(false){

}

cliente::cliente(const cliente& other)
    :nombre(other.nombre),contrasena(other.contrasena),id(other.id),edad(other.edad),tipo(other.tipo),
    cliente_seleccionado(false){

}

cliente::~cliente(){

}

string cliente::toString()const{
    stringstream ss;
    ss << "Nombre: " << nombre;
    return ss.str();
}
string cliente::getNombre()const{
    return nombre;
}
string cliente::getContrasena()const{
    return contrasena;
}
string cliente::getID()const{
    return id;
}
int cliente::cliente::getEdad()const{
    return edad;
}
string cliente::getTipo()const{
    return tipo;
}
bool cliente::getClienteSeleccionado()const{
    return cliente_seleccionado;
}
void cliente::setNombre(string nombre){
    this->nombre = nombre;
}

void cliente::setContrasena(string contrasena){
    this->contrasena = contrasena;
}

void cliente::setEdad(int edad){
    this->edad = edad;
}

void cliente::setTipo(string tipo){
    this->tipo = tipo;
}
void cliente::setClienteSeleccionado(){
    this->cliente_seleccionado = true;
}
double cliente::getDescuento(double precio) const{
    return 0;
}
