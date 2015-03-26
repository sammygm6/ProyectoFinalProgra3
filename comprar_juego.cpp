#include "comprar_juego.h"
#include "ui_comprar_juego.h"
#include <QStringList>
#include <typeinfo>
#include <iostream>
#include <QMessageBox>
#include <QString>

using namespace std;
using std::stringstream;

comprar_juego::comprar_juego(vector<juego*>* j,vector<cliente*>* c,string nombre,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comprar_juego)
{
    juegos = j;
    clientes = c;
    this->nombre = nombre;
    ui->setupUi(this);

    QStringList Lista;
    for(int i = 0; i<juegos->size(); i++){
        Lista.append(QString(juegos->at(i)->getNombre().c_str()));
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
   double descuento = 0;
   double precio = juegos->at(index)->getPrecio();
   cout << "Nombre------" << this->nombre << endl;
   for(int i=0; i<clientes->size(); i++){
       if(clientes->at(i)->getNombre() == this->nombre){
            descuento = clientes->at(i)->getDescuento(precio);
           cout << "Descuento: " << descuento << endl;
       }
   }
   ui->dsb_cj_precio->setValue(juegos->at(index)->getPrecio()-descuento);
   ui->le_cj_nombre->setText(QString(juegos->at(index)->getNombre().c_str()));
   ui->le_cj_clasificacion->setText(QString(juegos->at(index)->getClasificacion().c_str()));
   ui->le_cj_genero->setText(QString(juegos->at(index)->getTipo().c_str()));
   ui->dsb_cj_precio->setValue(juegos->at(index)->getPrecio() - descuento);
}

void comprar_juego::on_pushButton_2_clicked()
{
    this->close();
}

void comprar_juego::on_pushButton_clicked()
{
    double descuento = 0;
    double precio = juegos->at(ui->cb_cj_juegos->currentIndex())->getPrecio();
    cout << "Nombre------" << this->nombre << endl;
    for(int i=0; i<clientes->size(); i++){
        if(clientes->at(i)->getNombre() == this->nombre){
             descuento = clientes->at(i)->getDescuento(precio);
        }
    }
    double total = precio - descuento;

    QString salida_total = "Disfrute su compra\n\n"
                          "Precio de juego: " + QString::number(precio) + "\n"
                          "Descuento: " + descuento + "\n"
                          "Total: " + QString::number(total);

    juegos->erase(juegos->begin()+ui->cb_cj_juegos->currentIndex());
    QMessageBox::information(this,tr("Factura"),"Disfrute su compra\n\n"
                                                "Precio de juego:   " + QString::number(precio) + "\n"
                                                "Descuento:     " + QString::number(descuento) + "\n"
                                                "           Total: " + QString::number(total));
    this->close();
}
