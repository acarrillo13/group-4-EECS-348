#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BiTree.h"

#include <QString>
#include <string>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_enterButton_clicked()
{
    QString q_exp = ui->expText->text();
    string str_exp = q_exp.toStdString();

    BiTree tree;
    string str_res = tree.calculateEq(str_exp);

    QString q_res = QString::fromStdString(str_res);

    ui->resultText->setText(q_res);

}

