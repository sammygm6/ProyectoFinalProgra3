#include "comprar_juego.h"
#include "ui_comprar_juego.h"
#include <QStringList>

#include <iostream>

using namespace std;

comprar_juego::comprar_juego(vector<juego>* j,vector<cliente>* c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comprar_juego)
{
    juegos = j;
    clientes = c;
    ui->setupUi(this);

    QStringList Lista;
    for(int i = 0; i<juegos->size(); i++){
        Lista.append(QString(((juego)juegos->at(i)).getNombre().c_str()));
    }
    ui->cb_cj_juegos->addItems(Lista);

}

comprar_juego::~comprar_juego()
{
    delete ui;
}

void comprar_juego::on_cb_cj_juegos_activated(const QString &arg1)
{

}

void comprar_juego::on_cb_cj_juegos_currentIndexChanged(int index)//funcion para el combobox
{
    cliente tmp();

    for(int i=0; i<clientes->size(); i++){
        if(((cliente)clientes->at(i)).getClienteSeleccionado()){
            cout << "Entro al if de Cliente seleccionado" << endl;
        }
    }




   ui->le_cj_nombre->setText(QString(((juego)juegos->at(index)).getNombre().c_str()));
   ui->le_cj_clasificacion->setText(QString(((juego)juegos->at(index)).getClasificacion().c_str()));
   ui->le_cj_genero->setText(QString(((juego)juegos->at(index)).getTipo().c_str()));
}

void comprar_juego::on_pushButton_2_clicked()
{
    this->close();
}

void comprar_juego::on_pushButton_clicked()
{
    juegos->erase(juegos->begin()+ui->cb_cj_juegos->currentIndex());
    this->close();
}
