#ifndef UTXOWIDGET_H
#define UTXOWIDGET_H

#include <QWidget>
#include "tx.hpp"

namespace Ui {
class UTXOWidget;
}

class UTXOWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UTXOWidget(QWidget *parent = nullptr);
    ~UTXOWidget();

    inline void setBackgroundColor(QColor color)
    {
        setStyleSheet("background-color:black;");
        QPalette pal = palette();
        pal.setColor(QPalette::Base, color);
        this->setAutoFillBackground(true);
        this->setPalette(pal);
        //show();
    }

private:
    Ui::UTXOWidget *ui;
};

#endif // UTXOWIDGET_H
