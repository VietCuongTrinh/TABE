#ifndef DECRYPT_H
#define DECRYPT_H

#include "setup.h"
#include "encrypt.h"
#include "keygen.h"

void decrypt(element_t Ki,
             PublicParams &pp,
             Ciphertext &ct,
             SecretKey &sk);

#endif
