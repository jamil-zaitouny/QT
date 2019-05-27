#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // When the new Icon is pressed the textEdit be cleared
    void on_actionNew_triggered();

    //A prompt will ask the user to choose a file for reading
    void on_actionOpen_triggered();

    //The user will be prompted to save the file with a QFilePrompt
    void on_actionSave_triggered();

    //The user will prompted to choose the printer that he wants to print
    //the content of the textEdit
    void on_actionPrint_triggered();

    //The window will be closed
    void on_actionExit_triggered();

    //All the text inside the textEdit will be copited to the clipboard
    void on_actionCopy_triggered();

    //Everything in the clipboard will be pasted to the current textEdit
    void on_actionPaste_triggered();

    //All the text inside the textEdit will be cut to the clipboard
    void on_actionCut_triggered();

    //The last text edit will be undone
    void on_actionUndo_triggered();

    //The last undo will redone
    void on_actionRedo_triggered();

private:
    Ui::MainWindow *ui;
    //Name of the currentFile if there's one
    QString currentFile = "";
};

#endif // MAINWINDOW_H
