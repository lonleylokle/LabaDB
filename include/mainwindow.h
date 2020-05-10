#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

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
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_actionQuit_2_triggered();
    void on_actionQuit_triggered();
    void on_actionOpen_database_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
 
