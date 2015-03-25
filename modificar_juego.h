#ifndef MODIFICAR_JUEGO_H
#define MODIFICAR_JUEGO_H

#include <QDialog>
#include "juego.h"
#include <vector>

using std::vector;

namespace Ui {
class modificar_juego;
}

class modificar_juego : public QDialog
{
    Q_OBJECT

public:
    explicit modificar_juego(vector<juego*>*,QWidget *parent = 0);
    ~modificar_juego();

private slots:
    void on_pushButton_clicked();

    void on_cb_mj_juegos_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

private:
    Ui::modificar_juego *ui;
    vector<juego*>* juegos;
};

#endif // MODIFICAR_JUEGO_H
