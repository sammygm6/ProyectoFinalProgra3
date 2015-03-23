#include "iniciar_sesion.h"
#include "ui_iniciar_sesion.h"
#include "comprar_juego.h"
#include <iostream>

#include <QMessageBox>

using std::cout;
using std::endl;

iniciar_sesion::iniciar_sesion(vector<cliente>* c,vector<juego>* j, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::iniciar_sesion)
{
    clientes = c;
    if(clientes->size() > 0){
        for(int i = 0; i < clientes->size(); i++){
            cout << clientes->at(i).toString() << endl;
        }
    }
    juegos = j;
    if(juegos->size() > 0){
        for(int i = 0; i < juegos->size(); i++){
            cout << juegos->at(i).toString() << endl;
        }
    }
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
            cliente tmp = clientes->at(i);
            if(tmp.getNombre() == nombre && tmp.getContrasena() == contrasena){//Aca el if encontro al cliente
                comprar_juego c_j(juegos,clientes);
                c_j.exec();
                this->close();
            }
       }

   }
}
