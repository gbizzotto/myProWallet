#ifndef TX_HPP
#define TX_HPP

#include <string>

struct UTXO
{
    std::string txid;
    unsigned int vout;
    std::uint64_t amount;
    std::string address;
    std::string label;
    unsigned int block_height;
    unsigned int block_time;
    bool rbf;
};

#endif // TX_HPP
