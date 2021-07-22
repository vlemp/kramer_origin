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
//временно закоментила здесь и попробовала перенести логику в кнопки, чтобы передавались значения. с корнями так не сработало
//но подумала, лучше пусть в кнопках лежат все действия, чем создавать отдельные войды
//void MainWindow::on_GenMatrix_clicked() //проверка работы таблицы с кнопкой и значениями //lerch start
//{
    //ui->tableWidget->setMaximumSize(tableWidget); проверка подгонки таблицы по размерам
//    int k = qrand() % 10;

//    ui->tableWidget->setRowCount(n);
//    ui->tableWidget->setColumnCount(n);

//    for(int i=0; i< ui->tableWidget->rowCount(); i++){
//        for(int j=0; j< ui->tableWidget->columnCount(); j++){
//            k = qrand() % 10;
//            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(k));

//            ui->tableWidget->setItem(i,j,itm);
//        }
//    }
   //ToDo();
//} //lerch finish



//void MainWindow::on_GetRoots_clicked()
//{
//    ui->roots->setRowCount(1);
//    ui->roots->setColumnCount(n);
//    for(int j=0; j< ui->tableWidget->columnCount(); j++){
//    QTableWidgetItem *itm2 = new QTableWidgetItem;
//    itm2->setText(out[j]);
//    ui->tableWidget->setItem(0,j,itm2);
//    }
//    ui->roots->setRowCount(1);
//    ui->roots->setColumnCount(n);

    //ui->roots->setItem(0,j,itm2);
//}
