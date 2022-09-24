#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(420,700);
    w = new GameWiget(this);
    setCentralWidget(w);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionRelax_bird_triggered()
{
    w->setRelaxBird_method();
}
void MainWindow::on_actionMad_bird_triggered()
{
    w->setMadBird_method();
}
void MainWindow::on_actionCrazy_bird_triggered()
{
    w->setCrazyBird_method();
}


void MainWindow::on_actionClassic_triggered()
{
    w->setClassicMap_method();
}


void MainWindow::on_actionExtreme_triggered()
{
    w->setExtremeMap_method();
}

