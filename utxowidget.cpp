#include "utxowidget.h"
#include "ui_utxowidget.h"

UTXOWidget::UTXOWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UTXOWidget)
{
    ui->setupUi(this);
}

UTXOWidget::~UTXOWidget()
{
    delete ui;
}
