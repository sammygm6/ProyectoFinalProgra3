#include "modificar_juego.h"
#include "ui_modificar_juego.h"
#include <QStringList>
#include <iostream>

using namespace std;


modificar_juego::modificar_juego(vector<juego>* j,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modificar_juego)
{
    juegos = j;
    ui->setupUi(this);
    QStringList Lista;
    for(int i=0; i<juegos->size();i++){

        Lista.append(QString(((juego)juegos->at(i)).getNombre().c_str()));
    }
    ui->cb_mj_juegos->addItems(Lista);
}

modificar_juego::~modificar_juego()
{
    delete ui;
}

void modificar_juego::on_pushButton_clicked()
{
    int pos = ui->cb_mj_juegos->currentIndex();
    string nombre = ui->le_mj_nombre->text().toStdString();
    double precio = ui->dsb_mj_precio->value();
    string clasificacion = ui->cb_mj_clasificacion->currentText().toStdString();
    string genero = ui->cb_mj_genero->currentText().toStdString();
    juegos->erase(juegos->begin()+pos);
    juegos->push_back(juego(nombre,precio,clasificacion,genero));
    this->close();
}

void modificar_juego::on_cb_mj_juegos_currentIndexChanged(int index)
{
    ui->le_mj_nombre->setText(((juego)juegos->at(index)).getNombre().c_str());
    ui->dsb_mj_precio->setValue(((juego)juegos->at(index)).getPrecio());
    int pos_clasificacion = 0;
    int pos_genero = 0;
    string clasificacion = ((juego)juegos->at(index)).getClasificacion();
    string genero = ((juego)juegos->at(index)).getTipo();

    if(clasificacion == "Ninos" ){
        pos_clasificacion = 0;
    }else if(clasificacion == "Toda Persona"){
                pos_clasificacion = 1;
           }else if(clasificacion == "Todos 10+"){
                    pos_clasificacion = 2;
           }else if(clasificacion == "Adolecente"){
                    pos_clasificacion = 3;
           }else if(clasificacion == "Maduro 17+"){
                    pos_clasificacion = 4;
           }else if(clasificacion == "Solo Adultos"){
                    pos_clasificacion = 5;
           }else if(clasificacion == "En Espera"){
                    pos_clasificacion = 6;
           }
    if(genero == "Accion" ){
        pos_clasificacion = 0;
    }else if(genero == "Disparos"){
                pos_genero = 1;
           }else if(genero == "Estrategia"){
                    pos_genero = 2;
           }else if(genero == "Simulacion"){
                    pos_genero = 3;
           }else if(genero == "Deporte"){
                    pos_genero = 4;
           }else if(genero == "Carreras"){
                    pos_genero = 5;
           }else if(genero == "Aventura"){
                    pos_genero = 6;
           }
    ui->cb_mj_clasificacion->setCurrentIndex(pos_clasificacion);
    ui->cb_mj_genero->setCurrentIndex(pos_genero);

}

void modificar_juego::on_pushButton_2_clicked()
{
    this->close();
}
