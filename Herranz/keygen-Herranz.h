#ifndef KEYGEN_H
#define KEYGEN_H

#include "setup.h"

struct UserKey {
    element_t x;
    element_t usk;
};

void keygen(const PublicParams &params, UserKey &user);

#endif