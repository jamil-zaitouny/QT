#include "calculator.h"
#include "ui_calculator.h"

#include <QMessageBox>

double calculationValue = 0.0;
bool divisionTrigger = false;
bool addTrigger = false;
bool multiplicationTrigger = false;
bool subtractionTrigger = false;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calculationValue));
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++){
        QString buttonName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(buttonName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(num_pressed()));
    }
    connect(ui->Add, SIGNAL(released()), this, SLOT(math_button_pressed()));
    connect(ui->Multiply, SIGNAL(released()), this, SLOT(math_button_pressed()));
    connect(ui->Subtract, SIGNAL(released()), this, SLOT(math_button_pressed()));
    connect(ui->Divide, SIGNAL(released()), this, SLOT(math_button_pressed()));

    connect(ui->Equals, SIGNAL(released()), this, SLOT(equal_button_pressed()));

    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(change_number_sign()));

    connect(ui->Clear, SIGNAL(released()), this, SLOT(clear_memory()));

    connect(ui->MemoryGet, SIGNAL(released()), this, SLOT(get_memory()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::num_pressed(){
    QPushButton *button = (QPushButton *) sender();
    QString buttonValue = button->text();
    QString displayValue = ui->Display->text();

    if((displayValue.toDouble() == 0) || (displayValue.toDouble() == 0.0)){
        ui->Display->setText(buttonValue);
    } else{
        QString newValue = displayValue + buttonValue;
        double newDoubleValue = newValue.toDouble();
        ui->Display->setText(QString::number(newDoubleValue, 'g', 16));
    }
}

void Calculator::math_button_pressed()
{
    divisionTrigger = false;
    multiplicationTrigger = false;
    addTrigger = false;
    subtractionTrigger = false;
    QString dispalyValue = ui->Display->text();
    calculationValue = dispalyValue.toDouble();

    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button->text();

    if(QString::compare(buttonValue, "/", Qt::CaseInsensitive) == 0){
        divisionTrigger = true;
    }else if(QString::compare(buttonValue, "*", Qt::CaseInsensitive) == 0){
        multiplicationTrigger = true;
    }else if(QString::compare(buttonValue, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    }else if(QString::compare(buttonValue, "-", Qt::CaseInsensitive) == 0){
        subtractionTrigger = true;
    }
    ui->Display->setText("");
}

void Calculator::equal_button_pressed()
{
    double solution = 0.0;
    QString displayValue = ui->Display->text();
    double doubleDisplayValue = displayValue.toDouble();
    if(addTrigger || subtractionTrigger || multiplicationTrigger || divisionTrigger){
        if(addTrigger){
            solution = calculationValue + doubleDisplayValue;
        }else if(subtractionTrigger){
            solution = calculationValue - doubleDisplayValue;
        }else if(multiplicationTrigger){
            solution = calculationValue * doubleDisplayValue;
        }else{
            solution = calculationValue / doubleDisplayValue;
        }
    }
    QMessageBox messageBox;
    messageBox.setText(QString::number(doubleDisplayValue));
    ui->Display->setText(QString::number(solution));
}

void Calculator::change_number_sign()
{
    QString displayValue = ui->Display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayValue)){
        double doubleDisplayValue = displayValue.toDouble();
        double doubleDisplayValueSign = -1 * doubleDisplayValue;
        ui->Display->setText(QString::number(doubleDisplayValueSign));
    }
}
void Calculator::clear_memory(){
    calculationValue = 0.0;
    ui->Display->setText(QString::number(calculationValue));
}

void Calculator::get_memory()
{
    ui->Display->setText(QString::number(calculationValue));
}

