#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamewiget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionRelax_bird_triggered();
    void on_actionMad_bird_triggered();
    void on_actionCrazy_bird_triggered();

    void on_actionClassic_triggered();

    void on_actionExtreme_triggered();

private:
    Ui::MainWindow *ui;
    GameWiget* w;
};
#endif // MAINWINDOW_H
