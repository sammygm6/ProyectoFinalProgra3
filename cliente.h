#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using std::string;


class cliente
{
    string nombre;
    string contrasena;
    string id;
    int edad;
    string tipo;
public:
    cliente(string,string,string,int,string);
    cliente(const cliente&);
    ~cliente();
    virtual string toString()const;
    string getNombre()const;
    string getContrasena()const;
    string getID()const;
    string getTipo()const;
    int getEdad()const;
    void setNombre(string);
    void setContrasena(string);
    void setTipo(string);
    void setEdad(int);
};

#endif // CLIENTE_H
