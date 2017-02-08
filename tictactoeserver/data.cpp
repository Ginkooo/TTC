#include "data.h"

QMutex* Data::mutex = new QMutex;
std::vector<User*>* Data::connectionArray = new std::vector<User*>;

std::vector<User*>* Data::getConnections()
{
    QMutexLocker locker(mutex);
    return connectionArray;
}
