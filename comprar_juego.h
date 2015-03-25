#ifndef COMPRAR_JUEGO_H
#define COMPRAR_JUEGO_H

#include <QDialog>
#include <string>
#include <vector>
#include "cliente.h"
#include "gold.h"
#include "normal.h"
#include "platinum.h"
#include "juego.h"

using std::string;
using std::vector;

namespace Ui {
class comprar_juego;
}

class comprar_juego : public QDialog
{
    Q_OBJECT

public:
    explicit comprar_juego(vector<juego>*,vector<cliente>*,string,QWidget *parent = 0);
    ~comprar_juego();

private slots:
    void on_cb_cj_juegos_activated(const QString &arg1);

    void on_cb_cj_juegos_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::comprar_juego *ui;
    vector<juego>* juegos;
    vector<cliente>* clientes;
    string nombre;
};

#endif // COMPRAR_JUEGO_H
