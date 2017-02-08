#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QObject>

class Message
{

public:
    QString command;
    QString param;
    void decodeMessage(QString message);
    QString encodeMessage(std::string cmd, std::string param);

};

#endif // MESSAGE_H
