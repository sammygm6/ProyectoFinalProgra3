#include "crear_cliente.h"
#include "ui_crear_cliente.h"
#include <iostream>

using namespace std;

crear_cliente::crear_cliente(vector<cliente>* c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crear_cliente)
{
    clientes = c;
    ui->setupUi(this);
}

crear_cliente::~crear_cliente()
{
    delete ui;
}

void crear_cliente::on_pushButton_clicked()
{
    if(ui->cb_n_tipo->currentIndex() == 0){
        clientes->push_back(normal(ui->le_n_nombre->text().toStdString(),
                                   ui->le_n_contrasena->text().toStdString(),
                                   ui->le_n_id->text().toStdString(),
                                   ui->sb_n_edad->value()));
        cout << "if Normal" << endl;
    }else if(ui->cb_n_tipo->currentIndex() == 1){
        clientes->push_back(gold(ui->le_n_nombre->text().toStdString(),
                                 ui->le_n_contrasena->text().toStdString(),
                                 ui->le_n_id->text().toStdString(),
                                 ui->sb_n_edad->value()));
        cout << "if Gold" << endl;
    }else if(ui->cb_n_tipo->currentIndex() == 2){
        clientes->push_back(platinum(ui->le_n_nombre->text().toStdString(),
                                     ui->le_n_contrasena->text().toStdString(),
                                     ui->le_n_id->text().toStdString(),
                                     ui->sb_n_edad->value()));
        cout << "if Platinum" << endl;
    }

    this->close();
}

void crear_cliente::on_pushButton_2_clicked()
{
    this->close();
}
