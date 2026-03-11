#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <vector>
#include <string>
#include "setup.h"

struct Ciphertext {
    element_t C1;
    element_t C2;
};

void encrypt(Ciphertext &ct,
             PublicParams &pp,
             const std::vector<std::string> &IDs,
             element_t session_key);

#endif
