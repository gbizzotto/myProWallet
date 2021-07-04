#ifndef TXOUTPUTWIDGET_H
#define TXOUTPUTWIDGET_H

#include <QWidget>

namespace Ui {
class TXOutputWidget;
}

class TXOutputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TXOutputWidget(QWidget *parent = nullptr);
    ~TXOutputWidget();

private slots:
    void on_changeAddressPushButton_clicked();

private:
    Ui::TXOutputWidget *ui;
};

#endif // TXOUTPUTWIDGET_H
