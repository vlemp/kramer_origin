#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>


#include <stdlib.h>
#include <QRandomGenerator>
#include <QTextStream>
#include <QTableWidget>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void MainWindow::on_GenMatrix_clicked() //проверка работы таблицы с кнопкой и значениями //lerch start
{
//(данные таблицы не совпадают с данными программы, стадия проверки)
    //ui->tableWidget->setMaximumSize(tableWidget); проверка подгонки таблицы по размерам
    int k = qrand() % 10;
    ui->tableWidget->setRowCount(n);
    ui->tableWidget->setColumnCount(n);

    for(int i=0; i< ui->tableWidget->rowCount(); i++){
        for(int j=0; j< ui->tableWidget->columnCount(); j++){
            k = qrand() % 10;
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(k));

            ui->tableWidget->setItem(i,j,itm);
        }
    }

    for (int i=0; i< ui->tableWidget->rowCount(); ++i)//вывод значений из таблицы в массив
    {
        for(int j=0; j< ui->tableWidget->columnCount(); j++){

            qDebug() << ui-> tableWidget->item(i,j)->text();
        }
        qDebug() << endl;
    }

} //lerch finish
