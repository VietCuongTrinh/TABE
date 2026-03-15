#ifndef DECRYPT_H
#define DECRYPT_H

#include "setup.h"
#include "encrypt.h"
#include "keygen.h"

bool Decrypt(
    PublicParams &param,
    SecretKey &sk,
    Ciphertext &ct,
    vector<int> user_attr,
    element_t &K
);

#endif
