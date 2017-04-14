#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "port.h"
#include "base.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();	

public slots:
    void onPlusActionTriggered();
    void onMinusActionTriggered();
    void onLoadActionTriggered();
    void onUnoadActionTriggered();

private:
	Ui::MainWindow *ui;
	QGraphicsScene *scene;
    Port           *port;
    Base           *base;
};

#endif // MAINWINDOW_H
