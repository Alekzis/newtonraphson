#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <cmath>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->METODO,SIGNAL(clicked()),this,SLOT(procesar()));//connect to process button
    QObject::connect(ui->BORRAR,SIGNAL(clicked()),this,SLOT(borrar()));//connect to deleted button
    QObject::connect(ui->SALIR,SIGNAL(clicked()),this,SLOT(close()));//button to exit

    //ui->METODO->setEnabled(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}
double MainWindow::funcion0(double c){
    return(exp(-c)-c); //original function

}
double MainWindow::funciond1(double c)
{
    return(-exp(-c)-1);// first derivative

}
double MainWindow::funciond2(double c)
{
    return(exp(-c));//second derivative

}
void MainWindow::procesar(){
 QString tmp1,tmp2,tmp3,tmp4;//temporary variables
 double x1=ui->X1->value();//value taken from spinbox X1
 double error=ui->ERROR->value();//value taken from the spinbox ERROR
 double uni=ui->ITERACIONES->value();//value taken from the spinbox ITERATIONS

 double ea=100;
 double it=0;//variable where the root is saved
 double ni=0;//number of iterations


if(uni==0){//unspecified interactions
     while (ea>error) {
        it=x1-(funcion0(x1)/funciond1(x1));//method
        ea=100*std::abs((it-x1)/it);//error calculation
        //ea=100*std::abs(-(funciond2(x1))/(2*(funciond1(x1))));//second derivative error

        x1=it;//substitute for the next case

        ni=ni+1;//accountant
     }

}
else//specified iterations

{
    while(ni<uni)
    {
        it=x1-(funcion0(x1)/funciond1(x1));//method
        ea=100*std::abs((it-x1)/it);//error
        //ea=100*std::abs(-(funciond2(x1))/(2*(funciond1(x1))));//second derivative error
        x1=it;//substitution
        ni=ni+1;//accountant
    }
}
tmp1.append("La Raiz es:").append(tmp2.setNum(it)).append("\n  Error:").append(tmp3.setNum(ea)).append("\n Number of iterations
:").append(tmp4.setNum(ni));
ui->TEXTO->setText(tmp1);//show the text

}

void MainWindow::borrar(){//erased
    ui->X1->setValue(0.0);//clears spinbox X1

    ui->ERROR->setValue(0.0);//erases spinbox ERROR

    ui->TEXTO->clear();//erase text screen

}

