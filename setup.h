#ifndef SETUP_H
#define SETUP_H

#include <pbc/pbc.h>

struct PublicParams {
    pairing_t pairing;
    element_t g;
    element_t ge;
    element_t g_alpha;

    vector<element_t> ge_alpha_powers;
    vector<element_t> e_g_ge_P0;

    vector<int> attributes;
};

struct MasterKey {
    element_t alpha;
};

struct SecretKey {
    map<int, element_t> D;  
};

struct Ciphertext {
    element_t C1;
    element_t C2;

    vector<vector<int>> S;
    vector<int> threshold;
};

void Setup(PublicParams &pp, MasterKey &msk);

#endif
