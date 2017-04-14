#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);

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
