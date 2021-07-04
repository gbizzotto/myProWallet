#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "feeeditorwidget.h"

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
    void on_addOutputPushButton_clicked();

    void on_removeOutputPushButton_clicked();

    void on_selectUTXOsPushButton_clicked();

private:
    Ui::MainWindow *ui;
    FeeEditorWidget * fee_widget;
};
#endif // MAINWINDOW_H
