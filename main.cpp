#include "Project_Qt_Access.h"
#include <QDebug>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Project_Qt_Access w;
    w.show();
    return a.exec();
}
