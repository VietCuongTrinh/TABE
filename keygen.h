#ifndef KEYGEN_H
#define KEYGEN_H

#include <string>
#include "setup.h"

struct SecretKey {
    std::string id;
    element_t sk;
};

void keygen(SecretKey &sk,
            PublicParams &pp,
            MasterKey &msk,
            const std::string &id);

#endif
