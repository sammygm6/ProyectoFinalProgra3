#include "mainwindow.h"
#include <QApplication>
#include "cliente.h"
#include "normal.h"
#include "gold.h"
#include "platinum.h"
#include "juego.h"
#include <vector>

using std::vector;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vector<cliente*>* clientes = new vector<cliente*>;
    vector<juego*>* juegos = new vector<juego*>;
    MainWindow w(clientes,juegos,0);
    w.show();

    return a.exec();
}
