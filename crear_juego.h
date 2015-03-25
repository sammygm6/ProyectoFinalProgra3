#ifndef CREAR_JUEGO_H
#define CREAR_JUEGO_H

#include <QDialog>
#include "juego.h"
#include <vector>

using std::vector;

namespace Ui {
class crear_juego;
}

class crear_juego : public QDialog
{
    Q_OBJECT

public:
    explicit crear_juego(vector<juego*>*,QWidget *parent = 0);
    ~crear_juego();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::crear_juego *ui;
    vector<juego*>* juegos;
};

#endif // CREAR_JUEGO_H
