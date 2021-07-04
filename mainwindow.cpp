#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utxospendwidget.h"
#include "txoutputwidget.h"
#include "chooseutxosdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->nLockTimeTypeComboBox->addItem("Block");
    ui->nLockTimeTypeComboBox->addItem("Unix Time");

    fee_widget = new FeeEditorWidget(ui->outputsGroupBox);
    ui->outputsGroupBox->layout()->addWidget(fee_widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addOutputPushButton_clicked()
{
    QListWidgetItem * item = new QListWidgetItem(ui->outputsListWidget);
    ui->outputsListWidget->addItem(item);
    TXOutputWidget * output = new TXOutputWidget(ui->outputsListWidget);
    item->setSizeHint(output->minimumSizeHint());
    ui->outputsListWidget->setItemWidget(item, output);
    ui->outputsListWidget->addItem(item);
}

void MainWindow::on_removeOutputPushButton_clicked()
{
    QModelIndexList selectedList = ui->outputsListWidget->selectionModel()->selectedIndexes(); // take the list of selected indexes
    std::sort(selectedList.begin(),selectedList.end(),[](const QModelIndex& a, const QModelIndex& b)->bool{return a.row()>b.row();}); // sort from bottom to top
    for(const QModelIndex& singleIndex : selectedList)
        delete ui->outputsListWidget->takeItem(singleIndex.row());
    ui->outputsListWidget->selectionModel()->reset();
}

void MainWindow::on_selectUTXOsPushButton_clicked()
{
    ChooseUTXOsDialog * dialog = new ChooseUTXOsDialog(this);
    dialog->setWindowModality(Qt::WindowModality::WindowModal);
    dialog->show();
}
