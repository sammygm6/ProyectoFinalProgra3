#include "crear_juego.h"
#include "ui_crear_juego.h"
#include <QMessageBox>
#include <iostream>

using namespace std;

crear_juego::crear_juego(vector<juego*>* j,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crear_juego)
{
    juegos = j;
    ui->setupUi(this);
}

crear_juego::~crear_juego()
{
    delete ui;
}

void crear_juego::on_pushButton_clicked()
{
    if(ui->le_cj_nombre->text().isEmpty()){
        QMessageBox::information(this,tr("Error"),tr("Ingresele Nombre al juego"));
    }else{
            juegos->push_back(new juego(ui->le_cj_nombre->text().toStdString(),
                                    ui->dsb_cj_precio->value(),
                                    ui->cb_cj_clasificacion->currentText().toStdString(),
                                    ui->cb_cj_genero->currentText().toStdString()));
            QMessageBox::information(this,tr("Exito"),tr("Juego Ingresado"));
            this->close();
    }
}

void crear_juego::on_pushButton_2_clicked()
{
    this->close();

}
