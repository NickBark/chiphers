#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Magic * magic_dialog = new Magic(this);
    magic_dialog->show();
    magic_dialog->move(this->pos().x()+50, this->pos().y()+50);
}

void MainWindow::on_pushButton_3_clicked()
{
    Empreror * empreror_dialog = new Empreror(this);
    empreror_dialog->show();
    empreror_dialog->move(this->pos().x()+100, this->pos().y()+100);
}

void MainWindow::on_pushButton_2_clicked()
{
    Winston * winston_dialog = new Winston(this);
    winston_dialog->show();
    winston_dialog->move(this->pos().x()+150, this->pos().y()+150);
}

void MainWindow::on_action_triggered()
{
    QApplication::quit();
}
