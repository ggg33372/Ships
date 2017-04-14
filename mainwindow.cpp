#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ship.h"

#include <QStyle>
#include <QGuiApplication>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);

    ui->toolBar->addAction("+", this, SLOT(onPlusActionTriggered()));
    ui->toolBar->addAction("-", this, SLOT(onMinusActionTriggered()));
    ui->toolBar->addAction("*", this, SLOT(onLoadActionTriggered()));
    ui->toolBar->addAction("/", this, SLOT(onUnoadActionTriggered()));

    Ship::createPolygons();

    port = new Port();
    scene->addItem(port);

    base = new Base();
    scene->addItem(base);

	for (int i=0; i<5; ++i)
	{
        Ship *ship = new Ship(qrand()*500/RAND_MAX-250, qrand()*400/RAND_MAX-200);
		if (qrand()<RAND_MAX/2)
			ship->setDirection(false);
		scene->addItem(ship);
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPlusActionTriggered()
{
    if (scene->items().size()<5)
    {
        Ship *ship = new Ship(qrand()*500/RAND_MAX-250, qrand()*400/RAND_MAX-200);
        if (qrand()<RAND_MAX/2)
            ship->setDirection(false);
        scene->addItem(ship);
    }
}

void MainWindow::onMinusActionTriggered()
{
    Ship *ship = qgraphicsitem_cast<Ship *>(scene->focusItem());
    if (ship)
    {
        scene->removeItem(ship);
        delete ship;
    }
}

void MainWindow::onLoadActionTriggered()
{
    port->load();
}

void MainWindow::onUnoadActionTriggered()
{
    base->unload();
}
