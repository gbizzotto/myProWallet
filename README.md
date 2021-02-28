# myProWallet
Full-control BTC wallet/node

## Goals:

- Manually choose UTXOs in new TXs
- Manually set fee per byte or total
- Set nLockTime
- Export/Import (un)signed TXs
- Allow Dbl spend for better control over RBF
- Write custom Script (as in redeem script)
- Scriptable (as in per-block or per-tx scripting in JS, lua, python or whater)
- Manage BIP32 wallets and unique private keys
- Keep the UTXO set for painless key addition
