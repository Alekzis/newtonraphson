#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double funcion0(double c);//function without deriving
    double funciond1(double c);//first derivative
    double funciond2(double c);//second derivative


private:
    Ui::MainWindow *ui;
public slots:

    void procesar();//process function
    void borrar();//erase function

};

#endif // MAINWINDOW_H
