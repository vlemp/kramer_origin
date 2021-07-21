#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int n = 5;

    void clearMemory(int** a, int n);
    void ToDo();
    int findDet(int** a, int n);
    void Changcol(int** a, int** b, int n);
    void lyambda (int** a, int n);

private slots:
    void on_GenMatrix_clicked();

    void on_GetAnswers_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
