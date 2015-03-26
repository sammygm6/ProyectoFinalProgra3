#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "juego.h"

using std::string;
using std::vector;


class cliente
{
    string nombre;
    string contrasena;
    string id;
    int edad;
    string tipo;
    vector<juego> juegos_comprados;
public:
    cliente(string,string,string,int,string);
    cliente(const cliente&);
    ~cliente();
    virtual string toString()const;
    virtual double getDescuento(double)const=0;
    string getNombre()const;
    string getContrasena()const;
    string getID()const;
    string getTipo()const;
    int getEdad()const;
    vector<juego> getJuegosComprados()const;
    void setNombre(string);
    void setContrasena(string);
    void setTipo(string);
    void setEdad(int);
    void addJuegoComprado(juego);
};

#endif // CLIENTE_H
