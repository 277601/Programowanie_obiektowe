#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QMainWindow>
#include <QPushButton>
#include <QLCDNumber>
#include <QLineEdit>
#include "kalkulator.h"
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonOFFClicked();
    void onNumberClicked();
    void onOperatorClicked();
    void onResultClicked();
    void handleMemoryOperation();
    void onMemoryClear();
    void onMemoryView();


    void showAboutAuthorInfo();


private:
    Ui::MainWindow *ui;
    Kalkulator *kalkulator;
    QString currentDisplay;
    double operand1;
    double operand2;
    QString currentOperator;

};
#endif
