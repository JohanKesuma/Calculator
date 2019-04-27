#include <QFileDialog>
#include <QDir>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "minmaxnorm.h"
#include "linreggradientdescent.h"
#include "calcoptionsdialog.h"
#include "dialogs/findreplacedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    calcTableModel(nullptr),
    settings(new QSettings(QDir::currentPath() + "/calculator.ini", QSettings::IniFormat))
{
    ui->setupUi(this);
    init();

}

MainWindow::~MainWindow()
{
    saveSettings();
    delete calcTableModel;
    delete settings;
    delete calcFind;
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath(), FILE_FILTER);
    if (!fileName.isEmpty()) {
        if (calcTableModel) {
            delete calcTableModel;
        }
        if (calcFind) {
            delete calcFind;
        }
        calcTableModel = new CalcTableModel(fileName);
        ui->calcTableView->setModel(calcTableModel);
        ui->mainStackedWidget->setCurrentIndex(1);
        calcFind = new CalcFind(ui->calcTableView, calcTableModel);
    }
}

void MainWindow::init()
{
    loadSettings();

    ui->mainStackedWidget->setCurrentIndex(0);
    ui->findUpButton->setDisabled(true);
    ui->findDownButton->setDisabled(true);
}

void MainWindow::saveSettings()
{
    settings->beginGroup("MainWindow");
    settings->setValue("windowRect", this->geometry());
    settings->endGroup();
}

void MainWindow::loadSettings()
{
    settings->beginGroup("MainWindow");
    QRect windowRect = settings->value("windowRect", this->geometry()).toRect();
    setGeometry(windowRect);
    settings->endGroup();
}

void MainWindow::on_openFileButton_clicked()
{
    openFile();
}

void MainWindow::on_actionOpen_triggered()
{
    openFile();
}

void MainWindow::on_actionMin_Max_triggered()
{
    if (calcTableModel) {
        QItemSelectionModel *selectionModel = ui->calcTableView->selectionModel();
        if (selectionModel->hasSelection()) {

            int rowCount = selectionModel->selectedIndexes().last().row() - selectionModel->selectedIndexes().first().row() + 1;
            if (rowCount < 1) {
                return;
            }
            QModelIndexList indexList = selectionModel->selectedIndexes();
            MinMaxNorm::exec(calcTableModel, &indexList);
        }
    }
}
void MainWindow::on_actionLinear_triggered()
{
    QModelIndexList indexList = ui->calcTableView->selectionModel()->selectedIndexes();
    LinRegGradientDescent::exec(calcTableModel, &indexList);
}

void MainWindow::on_actionOptions_triggered()
{
    CalcOptionsDialog dialog;
    dialog.exec();
}

void MainWindow::on_actionFind_triggered()
{
    if (ui->bottomFrame->isHidden()) {
        ui->bottomFrame->show();
    }
    ui->findLineEdit->setFocus();
}

void MainWindow::on_findUpButton_clicked()
{
    if (!calcFind->findUp(ui->findLineEdit->text())){
        ui->findStatusLabel->setText("Search key not found");
    } else {
        ui->findStatusLabel->setText("");
    }
}

void MainWindow::on_findDownButton_clicked()
{
    if (!calcFind->findDown(ui->findLineEdit->text())){
        ui->findStatusLabel->setText("Search key not found");
    } else {
        ui->findStatusLabel->setText("");
    }
}

void MainWindow::on_findLineEdit_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        ui->findUpButton->setDisabled(true);
        ui->findDownButton->setDisabled(true);
    } else {
        ui->findUpButton->setDisabled(false);
        ui->findDownButton->setDisabled(false);
    }
}

void MainWindow::on_actionFullScreen_triggered()
{
    if(ui->actionFullScreen->isChecked()){
        this->setWindowState(Qt::WindowState::WindowFullScreen);
        return;
    }

    this->setWindowState(Qt::WindowState::WindowNoState);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->bottomFrame->isVisible()) {
        ui->bottomFrame->hide();
    }
}

void MainWindow::on_actionFind_and_Replace_triggered()
{
    FindReplaceDialog dialog(ui->calcTableView, calcTableModel);
    dialog.exec();
}

void MainWindow::on_actionSelect_All_triggered()
{
    ui->calcTableView->selectAll();
}

void MainWindow::on_actionSelect_Column_triggered()
{
    if (ui->calcTableView->selectionModel()->hasSelection()) {
        ui->calcTableView->setSelectionMode(QAbstractItemView::MultiSelection);
        int firstSelectedCol = ui->calcTableView->selectionModel()->selectedIndexes().first().column();
        int lastSelectedCol = ui->calcTableView->selectionModel()->selectedIndexes().last().column();

        for (int i = firstSelectedCol; i <= lastSelectedCol; ++i) {
            ui->calcTableView->selectColumn(i);
        }
        ui->calcTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    }
}

void MainWindow::on_actionSelect_Row_triggered()
{
    if (ui->calcTableView->selectionModel()->hasSelection()) {
        ui->calcTableView->setSelectionMode(QAbstractItemView::MultiSelection);
        int firstSelectedRow = ui->calcTableView->selectionModel()->selectedIndexes().first().row();
        int lastSelectedRow = ui->calcTableView->selectionModel()->selectedIndexes().last().row();

        for (int i = firstSelectedRow; i <= lastSelectedRow; ++i) {
            ui->calcTableView->selectRow(i);
        }
        ui->calcTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    }
}
