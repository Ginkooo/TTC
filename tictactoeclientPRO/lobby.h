#ifndef LOBBY_H
#define LOBBY_H

#include <QDialog>
#include "controller.h"
#include <QStringList>

class Controller;

namespace Ui {
class Lobby;
}

class Lobby : public QDialog
{
    Q_OBJECT

public:
    explicit Lobby(Controller* controller, QWidget *parent = 0);
    ~Lobby();
    void updateUserList(QStringList list);
    void setChallangedText(QString text);

private:
    Ui::Lobby *ui;
    Controller* controller;

public slots:
    void acceptButtonClicked();
    void challangeButtonClicked();
};

#endif // LOBBY_H
