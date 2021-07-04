#include "utxospendwidget.h"
#include "ui_utxospendwidget.h"

UTXOSpendWidget::UTXOSpendWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UTXOSpendWidget)
{
    ui->setupUi(this);
}

UTXOSpendWidget::~UTXOSpendWidget()
{
    delete ui;
}
