#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

void MainWindow::openDatabase(QString fileName) {
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(fileName);
    if(!mydb.open()) {
      ui->labelStatus->setText("Failed to open the database");
    }else {
      ui->labelStatus->setText("Connected...");
    }

    model = new QSqlTableModel(this, mydb);
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    ui->actionOpenTable->setEnabled(true);
    openTable();
}

void MainWindow::openTable() {
    if(!mydb.open()) {
        QMessageBox::about(this, "Error", "Database not open");
        return;
    }
    bool ok;
    QString tableName = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                              tr("Table name:"), QLineEdit::Normal,
                                              QDir::home().dirName(), &ok);
    if (ok && !tableName.isEmpty()) {
        model->setTable(tableName);
        model->select();
        ui->tableView->setModel(model);
        QStringList headers;
        for(int i = 0; i < model->columnCount(); i++) {
          headers.append(model->headerData(i, Qt::Horizontal).toString());
        }

        ui->comboBox->addItems(headers);
        ui->btnAdd->setEnabled(true);
        ui->btnFind->setEnabled(true);
        ui->btnDelete->setEnabled(true);
    }
    QSqlError msg = model->lastError();
    if (msg.isValid()) {
        QMessageBox::about(this, "Error", msg.text());
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionOpenDatabase_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open a database", QDir::homePath());
    openDatabase(fileName);
}

void MainWindow::on_actionOpenTable_triggered() {
    openTable();
}

void MainWindow::on_actionQuit_triggered() {
    QApplication::quit();
}

void MainWindow::on_btnFind_clicked() {
    if (!ui->lineEditInput->text().isEmpty()) {
        model->setFilter(ui->comboBox->currentText()+"='"+ui->lineEditInput->text()+"'");
        model->selectRow(0);
    }else {
        model->setFilter("");
    }
}

void MainWindow::on_btnAdd_clicked() {

}

void MainWindow::on_btnDelete_clicked() {
    
}
 
