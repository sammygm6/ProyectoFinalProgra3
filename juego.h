#ifndef JUEGO_H
#define JUEGO_H
#include <string>

using std::string;

class juego
{
    string nombre;
    double precio;
    string clasificacion;
    string tipo;
public:
    juego(string,double,string,string);
    juego(const juego&);
    ~juego();
    string toString()const;
    string getNombre()const;
    double getPrecio()const;
    string getClasificacion()const;
    string getTipo()const;
    void setNombre(string);
    void setPrecio(double);
    void setClasificacion(string);
    void setTipo(string);
};

#endif // JUEGO_H
