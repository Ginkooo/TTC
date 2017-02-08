#include "message.h"
#include <string>

void Message::decodeMessage(QString message)
{
    std::string msg = message.toStdString();
    std::string cmd = msg.substr(0, 3);
    std::string param = msg.substr(4, msg.length());
    while (param.find('\n') != -1)
    {
        param = param.replace(param.find('\n'), sizeof('\n'), "");
    }

    while (param.find('\r') != -1)
    {
        param = param.replace(param.find('\r'), sizeof('\r'), "");
    }

    this->command = QString::fromStdString(cmd);
    this->param = QString::fromStdString(param);
}

QString Message::encodeMessage(std::string cmd, std::string param)
{
    QString message = QString::fromStdString(cmd + " " + param + "\r\n");
    return message;
}
