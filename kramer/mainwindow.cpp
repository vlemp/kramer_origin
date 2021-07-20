#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdlib.h>
#include <QRandomGenerator>
#include <QTextStream>
#include <QTableWidget>
#include <QMessageBox>

QTextStream cout(stdout);
QTextStream cin(stdin);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ToDo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearMemory(int** a, int n) {
    for (int i = 0; i < n; i++) {
            delete[] a[i];
        }
        delete [] a;
    }
int MainWindow::findDet(int** a, int n) { //Рекурсивная функция вычисления определителя матрицы
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else {
        int d = 0;
        for (int k = 0; k < n; k++) {
            int** m = new int*[n-1];
                for (int i = 0; i < n - 1; i++) {
                    m[i] = new int[n - 1];
            }
            for (int i = 1; i < n; i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i-1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * a[0][k] * findDet(m, n - 1);
            clearMemory(m, n - 1); //Освобождаем память, выделенную под алгебраическое дополнение
        }
        return d; //Возвращаем определитель матрицы
    }
}
void MainWindow::Changcol(int** a, int** b, int n)
{
    int** c = new int*[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = new int[n];
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] = a[i][j];
                if (j == k)
                {
                     c[i][j] = b[i][0];
                 }

                 cout << c[i][j] << " ";
                 //cout << c[i][j] << " ";
             }
             cout << endl;
             //cout << endl;
         }
         cout << "The Root " << k+1 << ": " << (float)findDet(c, n)/findDet(a, n) << endl;
         cout << endl;
         //cout << endl;
     }

  clearMemory(c, n);
 }

void MainWindow::lyambda (int** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

        }
    }
}

void MainWindow::ToDo() {
 qsrand(qrand());
 int n = 5;
 cout << "Enter a matrix size: " << endl;
cout << "n = " << n << endl;
//cin >> n; //Вводим размерность матрицы
int** a = new int*[n]; //Объявляем двумерный целочисленный динамический массив (матрицу)
for (int i = 0; i < n; i++)
{
    a[i] = new int[n];
}
cout << "Enter a matrix: " << endl;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        a[i][j] = qrand() % 10; //Вводим элементы матрицы
        cout << a[i][j] << " ";
    }
    cout << endl;
}
cout << endl;
int** b = new int*[n]; //Объявляем вектор b
for (int i = 0; i < n; i++)
{
    b[i] = new int[n];
}
cout << "Vector b: " << endl;
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < 1; j++)
    {
        b[i][j] = qrand() % 10;//Вводим вектор B
        cout << b[i][j] << " ";
    }
    cout << endl;
}
cout << endl;
Changcol(a, b, n);
cout << "Found determinant: " << findDet(a, n) << endl; //Вызываем рекурсивную функцию вычисления определителя матрицы
clearMemory(a, n); //Освобождаем память, выделенную под исходную матрицу
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
} //lerch finish
