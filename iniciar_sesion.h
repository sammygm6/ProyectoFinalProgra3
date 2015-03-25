#ifndef INICIAR_SESION_H
#define INICIAR_SESION_H

#include <QDialog>
#include <vector>
#include "cliente.h"
#include "juego.h"
#include <string>

using std::vector;
using std::vector;

namespace Ui {
class iniciar_sesion;
}

class iniciar_sesion : public QDialog
{
    Q_OBJECT

public:
    explicit iniciar_sesion(vector<cliente*>*, vector<juego*>*,QWidget *parent = 0);
    ~iniciar_sesion();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::iniciar_sesion *ui;
    vector<cliente*>* clientes;
    vector<juego*>* juegos;
};

#endif // INICIAR_SESION_H
