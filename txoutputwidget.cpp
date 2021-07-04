#include "txoutputwidget.h"
#include "ui_txoutputwidget.h"

TXOutputWidget::TXOutputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TXOutputWidget)
{
    ui->setupUi(this);
    ui->comboBox->addItem("P2PK");
    ui->comboBox->addItem("P2PKH");
    ui->comboBox->addItem("P2SH");
    ui->comboBox->addItem("Multisig (P2SH)");
    ui->comboBox->addItem("SegWit (P2WPKH)");
    ui->comboBox->addItem("OP_RETURN MSG");
    ui->comboBox->setCurrentIndex(1);
}

TXOutputWidget::~TXOutputWidget()
{
    delete ui;
}

void TXOutputWidget::on_changeAddressPushButton_clicked()
{
    ui->addressValueLineEdit->setText("bc1qmychangeaddress");
    ui->lockAmountCheckBox->setChecked(false);
    ui->comboBox->setCurrentIndex(3);
}
