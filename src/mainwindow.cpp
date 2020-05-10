#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

        mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/xhazker/C++Projects/LabaDB/res/database.db");
    if(!mydb.open()) {
      ui->label->setText("Failed to open the database");
    }else {
      ui->label->setText("Connected...");
    }

    model = new QSqlTableModel(this, mydb);
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->setTable("demo");
    model->select();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionOpen_database_triggered() {

}

void MainWindow::on_actionQuit_triggered() {

}

void MainWindow::on_actionQuit_2_triggered() {

}

void MainWindow::on_pushButton_clicked() {

}

void MainWindow::on_pushButton_2_clicked() {

}

void MainWindow::on_pushButton_3_clicked() {
    
}
 
