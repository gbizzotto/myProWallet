#include "chooseutxosdialog.h"
#include "ui_chooseutxosdialog.h"
#include "utxowidget.h"
#include <qcheckbox.h>
#include <string>
#include <stdlib.h>
#include <QCryptographicHash>
#include <string_view>
#include <sstream>
#include <iomanip>
#include "tx.hpp"

// satoshi's EncodeBase58
static const char* pszBase58 = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
std::string EncodeBase58(std::basic_string_view<unsigned char> input)
{
    // Skip & count leading zeroes.
    int zeroes = 0;
    int length = 0;
    while (input.size() > 0 && input[0] == 0) {
        input.remove_prefix(1);
        zeroes++;
    }
    // Allocate enough space in big-endian base58 representation.
    int size = input.size() * 138 / 100 + 1; // log(256) / log(58), rounded up.
    std::vector<unsigned char> b58(size);
    // Process the bytes.
    while (input.size() > 0) {
        int carry = input[0];
        int i = 0;
        // Apply "b58 = b58 * 256 + ch".
        for (std::vector<unsigned char>::reverse_iterator it = b58.rbegin(); (carry != 0 || i < length) && (it != b58.rend()); it++, i++) {
            carry += 256 * (*it);
            *it = carry % 58;
            carry /= 58;
        }

        assert(carry == 0);
        length = i;
        input.remove_prefix(1);
    }
    // Skip leading zeroes in base58 result.
    std::vector<unsigned char>::iterator it = b58.begin() + (size - length);
    while (it != b58.end() && *it == 0)
        it++;
    // Translate the result into a string.
    std::string str;
    str.reserve(zeroes + (b58.end() - it));
    str.assign(zeroes, '1');
    while (it != b58.end())
        str += pszBase58[*(it++)];
    return str;
}

std::string DblSha256(const std::string & s)
{
    auto hasher = QCryptographicHash(QCryptographicHash::Sha256);
    hasher.addData(s.c_str(), s.size());
    QByteArray intermediate_hash = hasher.result();
    return QCryptographicHash::hash(intermediate_hash, QCryptographicHash::Sha256).toStdString();
}

std::string Base58Check(std::string v)
{
    auto hash = DblSha256(v);
    v.append(&*hash.begin(), &*(hash.begin()+4));
    return EncodeBase58({(unsigned char*)&*v.begin(), v.size()});
}

std::string Hex(std::string s)
{
    const char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    std::string result;
    result.reserve(s.size()*2);
    for (char c : s)
    {
        result.push_back(hex[(c>>4)&0xF]);
        result.push_back(hex[c&0xF]);
    }
    return result;
}

ChooseUTXOsDialog::ChooseUTXOsDialog(std::vector<UTXO> p_utxos, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseUTXOsDialog),
    utxos(std::move(p_utxos))
{
    ui->setupUi(this);

    ui->UTXOsTableWidget->setColumnCount(6);
    ui->UTXOsTableWidget->setHorizontalHeaderLabels({"Select", "Amount", "Confirmations", "Address", "TXID", "vout"});

    for (int i=0 ; i<utxos.size() ; i++)
    {
        const UTXO & utxo = utxos[i];

        ui->UTXOsTableWidget->insertRow(ui->UTXOsTableWidget->rowCount());

        QCheckBox *checkbox = new QCheckBox();
        ui->UTXOsTableWidget->setCellWidget(i, 0, checkbox);

        auto amount_str = std::to_string(rand()%10).append(".").append(std::to_string(rand()%1000000000));
        ui->UTXOsTableWidget->setItem(i, 1, new QTableWidgetItem(amount_str.c_str()));
        ui->UTXOsTableWidget->item(i, 1)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->UTXOsTableWidget->item(i, 1)->setFont(QFont("courier new"));

        ui->UTXOsTableWidget->setItem(i, 2, new QTableWidgetItem(std::to_string(rand()%10).c_str()));
        ui->UTXOsTableWidget->item(i, 2)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

        std::string key_hash(1, 0); // P2PKH address prefix
        for (int i=0 ; i<20 ; i++)
            key_hash.append(1, (char)rand()%256);
        ui->UTXOsTableWidget->setItem(i, 3, new QTableWidgetItem(Base58Check(key_hash).c_str()));
        ui->UTXOsTableWidget->item(i, 3)->setFont(QFont("courier new"));

        std::string tx;
        tx.reserve(32);
        for (int i=0 ; i<32 ; i++)
            tx.append(1, (char)rand()%256);
        ui->UTXOsTableWidget->setItem(i, 4, new QTableWidgetItem(Hex(DblSha256(tx)).c_str()));
        ui->UTXOsTableWidget->item(i, 4)->setFont(QFont("courier new"));

        ui->UTXOsTableWidget->setItem(i, 5, new QTableWidgetItem(std::to_string(rand()%16).c_str()));
    }
}

ChooseUTXOsDialog::~ChooseUTXOsDialog()
{
    delete ui;
}

std::vector<UTXO> ChooseUTXOsDialog::getSelectedUTXOs()
{

}
