#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>


#include <stdlib.h>
#include <QRandomGenerator>
#include <QTextStream>
#include <QTableWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


void MainWindow::on_GenMatrix_clicked(){

    int k = qrand() % 10;

    ui->tableWidget->setRowCount(n);
    ui->tableWidget->setColumnCount(n+1);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() <<"1"<<"2"<<"3"<<"4"<<"5"<<"b");
    for(int i=0; i< ui->tableWidget->rowCount(); i++){
        for(int j=0; j< ui->tableWidget->columnCount(); j++){
            k = qrand() % 10;
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(k));

            ui->tableWidget->setItem(i,j,itm);
        }
    }
}

void MainWindow::on_GetRoots_clicked()
{
    ToDo();
}
