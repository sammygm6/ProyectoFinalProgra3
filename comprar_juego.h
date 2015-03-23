#ifndef COMPRAR_JUEGO_H
#define COMPRAR_JUEGO_H

#include <QDialog>
#include <string>
#include <vector>
#include "cliente.h"
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
    explicit comprar_juego(vector<juego>*,vector<cliente>*,QWidget *parent = 0);
    ~comprar_juego();

private slots:
    void on_cb_cj_juegos_activated(const QString &arg1);

    void on_cb_cj_juegos_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

private:
    Ui::comprar_juego *ui;
    vector<juego>* juegos;
    vector<cliente>* clientes;
};

#endif // COMPRAR_JUEGO_H
