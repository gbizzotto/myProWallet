#ifndef UTXOSPENDWIDGET_H
#define UTXOSPENDWIDGET_H

#include <QWidget>

namespace Ui {
class UTXOSpendWidget;
}

class UTXOSpendWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UTXOSpendWidget(QWidget *parent = nullptr);
    ~UTXOSpendWidget();

private:
    Ui::UTXOSpendWidget *ui;
};

#endif // UTXOSPENDWIDGET_H
