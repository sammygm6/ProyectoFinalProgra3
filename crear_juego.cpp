#include "crear_juego.h"
#include "ui_crear_juego.h"
#include <QMessageBox>

crear_juego::crear_juego(vector<juego>* j,QWidget *parent) :
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
    juegos->push_back(juego(ui->le_cj_nombre->text().toStdString(),
                            ui->dsb_cj_precio->value(),
                            ui->cb_cj_clasificacion->currentText().toStdString(),
                            ui->cb_cj_genero->currentText().toStdString()));
    QMessageBox::information(this,tr("Exito"),tr("Juego Ingresado"));
    this->close();
}

void crear_juego::on_pushButton_2_clicked()
{
    this->close();

}
