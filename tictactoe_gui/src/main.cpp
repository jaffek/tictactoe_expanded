#include "mainwindow.h"


int N;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.czygra(1);
    w.rozmiar(N);
    w.newPos();
    w.show();

    return a.exec();
}
