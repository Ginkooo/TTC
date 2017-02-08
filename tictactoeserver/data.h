#ifndef DATA_H
#define DATA_H

#include <vector>
#include "user.h"
#include <QMutex>
#include <QMutexLocker>

class Data
{
public:
    static std::vector<User*>* getConnections();

private:
    static QMutex* mutex;
    static std::vector<User*> *connectionArray;
};

#endif // DATA_H
