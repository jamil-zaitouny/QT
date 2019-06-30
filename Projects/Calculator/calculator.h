#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void num_pressed();
    void math_button_pressed();
    void equal_button_pressed();
    void change_number_sign();
    void clear_memory();
    void get_memory();


};

#endif // CALCULATOR_H
