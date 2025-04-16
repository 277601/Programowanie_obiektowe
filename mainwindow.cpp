#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLCDNumber>
#include <QApplication>
#include <QTimer>
#include <QMessageBox>
#include <QString>
#include <QChar>
#include "kalkulator.h"
#include <iostream>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , operand1(0)
    , operand2(0)

{

    setFixedSize(800,600);

    ui->setupUi(this);
    kalkulator = new Kalkulator();

    connect(ui->button_0, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button_1, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button_2, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button_3, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button_4, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button_5, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button_6, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button_7, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button_8, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button_9, &QPushButton::clicked, this, &MainWindow::onNumberClicked);

    connect(ui->Dodawanie, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->Odejmowanie, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->Mnozenie, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->Dzielenie, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->reszta, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);

    connect(ui->button_wynik, &QPushButton::clicked, this, &MainWindow::onResultClicked);
    connect(ui->button_OFF, &QPushButton::clicked, this, &MainWindow::onButtonOFFClicked);
    connect(ui->M_plus, &QPushButton::clicked, this, &MainWindow::handleMemoryOperation);
    connect(ui->M_minus, &QPushButton::clicked, this, &MainWindow::handleMemoryOperation);
    connect(ui->MC, &QPushButton::clicked, this, &MainWindow::handleMemoryOperation);
    connect(ui->MRC, &QPushButton::clicked, this, &MainWindow::onMemoryClear);
    connect(ui->actionAboutAuthor, &QAction::triggered, this, &MainWindow::showAboutAuthorInfo);



}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onButtonOFFClicked()
{
    ui->Liczniik->display("OFF");
    QTimer::singleShot(1000, this, &MainWindow::close);
}
void MainWindow::onNumberClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        currentDisplay += button->text();
        ui->Liczniik->display(currentDisplay);
    }
}
void MainWindow::onOperatorClicked()
{
    QPushButton *button =qobject_cast<QPushButton *> (sender());
    if (button) {
        operand1 = currentDisplay.toDouble();
        currentDisplay.clear();
        if (button == ui->Dodawanie) {
           currentOperator = "+";
        }
        else if (button == ui->Odejmowanie) {
            currentOperator = "-";
        }
        else if (button == ui->Mnozenie) {
            currentOperator = "*";
        }
        else if (button == ui->Dzielenie) {
            currentOperator = "/";
        }
        else if (button == ui->reszta) {
           currentOperator = "%";
        }
    }
}

    void MainWindow::onResultClicked()
{
        if (currentOperator == "/") {
            if (operand2 == 0) {
                QMessageBox::warning(this, "Błąd dzielenia", "Nie można dzielić przez zero!");
                ui->Liczniik->display(0);
                currentDisplay = "0";
                return;
            }
            else {
                double result = operand1 / operand2;
                ui->Liczniik->display(result);
                currentDisplay = QString::number(result);
            }
        }
    operand2 =currentDisplay.toDouble();
    double result = 0;
    if(currentOperator == "+"){
        result = kalkulator->dodawanie(operand1,operand2);
    }
    else if(currentOperator == "-"){
        result = kalkulator->odejmowanie(operand1,operand2);

    }
    else if(currentOperator == "*"){
        result = kalkulator->mnozenie(operand1,operand2);
    }
    else if (currentOperator == "/") {
        result = kalkulator->dzielenie(operand1, operand2);
    }
    else if (currentOperator == "%") {
        result = kalkulator->reszta(operand1, operand2);
    }
    ui->Liczniik->display(result);
    currentDisplay.clear();
}

void MainWindow::handleMemoryOperation()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button == ui->M_plus) {
        double displayValue = ui->Liczniik->value();
        cout << "M+ - Display value: " << displayValue << endl;
        kalkulator->setAkumulator(displayValue);
        kalkulator->M_plus();
    } else if (button == ui->M_minus) {
        double displayValue = ui->Liczniik->value();
        cout << "M- - Display value: " << displayValue << endl;
        kalkulator->setAkumulator(displayValue);
        kalkulator->M_minus();
    }
    cout << "Memory value: " << kalkulator->getPamiec() << endl;
    ui->Liczniik->display(kalkulator->getPamiec());
    currentDisplay.clear();
}
void MainWindow::onMemoryClear()
{
    kalkulator->M_clear();
    ui->Liczniik->display("0");
}
void MainWindow::onMemoryView(){
    ui->Liczniik->display(kalkulator->getPamiec());
}




void MainWindow::showAboutAuthorInfo()
{
    QMessageBox::information(this, "O autorze","Informacje autorze :\n Karol Kościelski");
}





