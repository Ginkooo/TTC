#include <QCoreApplication>
#include "ttcserver.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TTCServer* server = new TTCServer();
    return a.exec();
}
