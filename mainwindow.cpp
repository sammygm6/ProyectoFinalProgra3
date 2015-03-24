#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crear_cliente.h"
#include "iniciar_sesion.h"
#include "crear_juego.h"
#include "modificar_juego.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    clientes = new vector<cliente>();
    juegos = new vector<juego>();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    crear_cliente cc(clientes);
    cc.exec();
}

void MainWindow::on_pushButton_clicked()
{
    iniciar_sesion is(clientes,juegos);
    is.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    string pass = QInputDialog::getText(this,"Administrador","Ingrese password: "
                                                              "\nhint: admin").toStdString();
    if(pass == "admin"){
    crear_juego cj(juegos);
    cj.exec();
    }else{
        QMessageBox::information(this,tr("Error Fatal"),tr("Ingreso un password incorrecto"));
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    string pass = QInputDialog::getText(this,"Administrador","Ingrese el Password: "
                                                                            "\nhint: admin").toStdString();
    if(pass == "admin"){
    modificar_juego mj(juegos);
    mj.exec();
    }else{
        QMessageBox::information(this,tr("Error Fatal"),tr("Ingreso un password incorrecto"));
    }
}
