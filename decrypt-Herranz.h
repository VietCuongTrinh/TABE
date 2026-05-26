#ifndef DECRYPT_H
#define DECRYPT_H

#include "encrypt.h"

struct Share {
    element_t sigma;
};

void share_decrypt(
    const PublicParams &params,
    const UserKey &user,
    const Ciphertext &ct,
    Share &share
);

#endif