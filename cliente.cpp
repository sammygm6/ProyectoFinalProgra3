#include "cliente.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

cliente::cliente(string nombre,string contrasena,string id,int edad)
    :nombre(nombre),contrasena(contrasena),id(id),edad(edad){

}

cliente::cliente(const cliente& other)
    :nombre(other.nombre),contrasena(other.contrasena),id(other.id),edad(other.edad){

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
void cliente::setNombre(string nombre){
    this->nombre = nombre;
}

void cliente::setContrasena(string contrasena){
    this->contrasena = contrasena;
}

void cliente::setEdad(int edad){
    this->edad = edad;
}
