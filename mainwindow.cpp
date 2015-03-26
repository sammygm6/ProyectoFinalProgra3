#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crear_cliente.h"
#include "iniciar_sesion.h"
#include "crear_juego.h"
#include "modificar_juego.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(vector<cliente*>*,vector<juego*>*,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    clientes = new vector<cliente*>;
    juegos = new vector<juego*>;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    crear_cliente cc(clientes,0);
    cc.setModal(true);
    cc.exec();
}

void MainWindow::on_pushButton_clicked()
{
    if(juegos->empty()){
        QMessageBox::information(this,tr("Error"),tr("No hay juegos que comprar :("));
    }else{
        iniciar_sesion is(clientes,juegos,0);
        is.setModal(true);
        is.exec();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    string pass = QInputDialog::getText(this,"Administrador","Ingrese password: "
                                                              "\nhint: admin").toStdString();
    if(pass == "admin"){
    crear_juego cj(juegos,0);
    cj.setModal(true);
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
    modificar_juego mj(juegos,0);
    mj.setModal(true);
    mj.exec();
    }else{
        QMessageBox::information(this,tr("Error Fatal"),tr("Ingreso un password incorrecto"));
    }
}
