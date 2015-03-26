#include "iniciar_sesion.h"
#include "ui_iniciar_sesion.h"
#include "comprar_juego.h"
#include <iostream>
#include <QMessageBox>
#include <QString>

using std::cout;
using std::endl;

iniciar_sesion::iniciar_sesion(vector<cliente*>* c,vector<juego*>* j, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::iniciar_sesion)
{
    clientes = c;
    juegos = j;
    ui->setupUi(this);
}

iniciar_sesion::~iniciar_sesion()
{
    delete ui;
}

void iniciar_sesion::on_pushButton_2_clicked()
{
    this->close();
}

void iniciar_sesion::on_pushButton_clicked()
{
   string nombre = ui->le_login_nombre->text().toStdString();
   string contrasena = ui->le_login_contrasena->text().toStdString();
   if(clientes->empty()){
       QMessageBox::information(this,tr("Error"),tr("No Existe Ningun Dato"));
       ui->le_login_nombre->setText("");
       ui->le_login_contrasena->setText("");
   }else if(clientes->size() > 0){
            for(int i = 0; i < clientes->size(); i++){
                if((clientes->at(i)->getNombre() == nombre) &&
                        (clientes->at(i)->getContrasena() == contrasena)){//Aca el if encontro al cliente
                    clientes->at(i)->setClienteSeleccionado();
                    clientes->at(i)->setClienteSeleccionado();
                    comprar_juego c_j(juegos,clientes,clientes->at(i)->getNombre());
                    c_j.setModal(true);
                    c_j.exec();
                    this->close();
                    break;
                }else{
                    QMessageBox::information(this,tr("Error"),tr("Nombre o Contrasena incorrecto"));
                    ui->le_login_nombre->setText("");
                    ui->le_login_contrasena->setText("");
                    break;
            }
       }

   }
}
