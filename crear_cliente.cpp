#include "crear_cliente.h"
#include "ui_crear_cliente.h"
#include <QMessageBox>
#include <iostream>
#include "cliente.h"
#include "normal.h"
#include "gold.h"
#include "platinum.h"
#include <vector>

using namespace std;
using std::vector;

crear_cliente::crear_cliente(vector<cliente*>* c,QWidget *parent) :
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
    if(ui->le_n_nombre->text().isEmpty() || ui->le_n_contrasena->text().isEmpty() ||
            ui->le_n_id->text().isEmpty() || ui->sb_n_edad->value() <= 0){
        QMessageBox::information(this,tr("Error"),tr("No puede dejar algun campo vacio"));
    }else{
            if(ui->cb_n_tipo->currentIndex() == 0){
                clientes->push_back( new normal(ui->le_n_nombre->text().toStdString(),
                                               ui->le_n_contrasena->text().toStdString(),
                                               ui->le_n_id->text().toStdString(),
                                               ui->sb_n_edad->value(),
                                               ui->cb_n_tipo->currentText().toStdString()));
                //clientes->push_back(cliente_n);
                //cout << "Entro a crear una cuenta normal: " << cliente_n->getNombre() << endl;
                QMessageBox::information(this,tr("Felicitaciones"),tr("Creacion de cuenta exitosa"));
                this->close();
            }else if(ui->cb_n_tipo->currentIndex() == 1){
                gold* cliente_g = new gold(ui->le_n_nombre->text().toStdString(),
                                           ui->le_n_contrasena->text().toStdString(),
                                           ui->le_n_id->text().toStdString(),
                                           ui->sb_n_edad->value(),
                                           ui->cb_n_tipo->currentText().toStdString());

                clientes->push_back(cliente_g);
                cout << "Entro a crear una cuenta gold" << cliente_g->getNombre() << endl;
                QMessageBox::information(this,tr("Felicitaciones"),tr("Creacion de cuenta exitosa"));
                this->close();
            }else if(ui->cb_n_tipo->currentIndex() == 2){
                platinum* cliente_p = new platinum(ui->le_n_nombre->text().toStdString(),
                                                   ui->le_n_contrasena->text().toStdString(),
                                                   ui->le_n_id->text().toStdString(),
                                                   ui->sb_n_edad->value(),
                                                   ui->cb_n_tipo->currentText().toStdString());

                clientes->push_back(cliente_p);
                cout << "Entro a crear una cuenta platinum" << cliente_p->getNombre() << endl;
                QMessageBox::information(this,tr("Felicitaciones"),tr("Creacion de cuenta exitosa"));
                this->close();
            }

    }
}

void crear_cliente::on_pushButton_2_clicked()
{
    this->close();
}
