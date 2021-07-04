#ifndef CHOOSEUTXOSDIALOG_H
#define CHOOSEUTXOSDIALOG_H

#include <QDialog>
#include <vector>
#include "tx.hpp"

namespace Ui {
class ChooseUTXOsDialog;
}

class ChooseUTXOsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseUTXOsDialog(std::vector<UTXO>, QWidget *parent = nullptr);
    ~ChooseUTXOsDialog();
    std::vector<UTXO> getSelectedUTXOs();

private:
    Ui::ChooseUTXOsDialog *ui;
    std::vector<UTXO> utxos;
};

#endif // CHOOSEUTXOSDIALOG_H
