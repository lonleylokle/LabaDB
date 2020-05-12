#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QInputDialog>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();
    void on_btnFind_clicked();
    void on_btnDelete_clicked();
    void on_actionOpenDatabase_triggered();
    void on_actionOpenTable_triggered();
    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    QSqlTableModel *model;
    void openDatabase(QString file_name);
    void openTable();
};
#endif // MAINWINDOW_H
 
