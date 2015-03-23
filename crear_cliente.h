#ifndef CREAR_CLIENTE_H
#define CREAR_CLIENTE_H

#include <QDialog>
#include "cliente.h"
#include "normal.h"
#include "gold.h"
#include "platinum.h"
#include <vector>

using std::vector;

namespace Ui {
class crear_cliente;
}

class crear_cliente : public QDialog
{
    Q_OBJECT

public:
    explicit crear_cliente(vector<cliente>*,QWidget *parent = 0);
    ~crear_cliente();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::crear_cliente *ui;
    vector<cliente>* clientes;
};

#endif // CREAR_CLIENTE_H
