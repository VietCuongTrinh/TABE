#ifndef SETUP_H
#define SETUP_H

#include <pbc/pbc.h>

struct PublicParams {
    pairing_t pairing;
    element_t g;
    element_t g_tilde;
    element_t g_alpha;
    element_t egg_P0;
};

struct MasterKey {
    element_t alpha;
};

void setup(PublicParams &pp, MasterKey &msk);

#endif
