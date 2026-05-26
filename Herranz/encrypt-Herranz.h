#ifndef ENCRYPT_H
#define ENCRYPT_H

#include "keygen.h"

struct Ciphertext {
    element_t C1;
    element_t C2;
    element_t K;
};

void encrypt(
    const PublicParams &params,
    const std::vector<UserKey*> &users,
    int threshold,
    Ciphertext &ct
);

#endif