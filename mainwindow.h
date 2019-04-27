#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

#include "calctablemodel.h"
#include "calcfind.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void on_actionExit_triggered();

    void on_openFileButton_clicked();

    // private attr
    void on_actionOpen_triggered();

    void on_actionMin_Max_triggered();

    void on_actionLinear_triggered();

    void on_actionOptions_triggered();

    void on_actionFind_triggered();

    void on_findUpButton_clicked();

    void on_findDownButton_clicked();

    void on_findLineEdit_textChanged(const QString &arg1);

    void on_actionFullScreen_triggered();

    void on_pushButton_clicked();

    void on_actionFind_and_Replace_triggered();

    void on_actionSelect_All_triggered();

    void on_actionSelect_Column_triggered();

    void on_actionSelect_Row_triggered();

private:
    Ui::MainWindow *ui;
    CalcTableModel *calcTableModel;
    QSettings *settings;
    CalcFind *calcFind;

    // private func
private:
    void openFile();
    void init();
    void saveSettings();
    void loadSettings();
};

#endif // MAINWINDOW_H
