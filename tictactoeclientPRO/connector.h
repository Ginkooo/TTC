#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QDialog>
#include "ttcsocket.h"
#include "controller.h"

class Controller;

namespace Ui {
class Connector;
}

class Connector : public QDialog
{
    Q_OBJECT

public:
    explicit Connector(Controller* controller, QWidget *parent = 0);
    ~Connector();

private:
    Ui::Connector *ui;
    Controller* controller;

public slots:
    void connectClicked();
};

#endif // CONNECTOR_H
