#ifndef SETUP_H
#define SETUP_H

#include <pbc/pbc.h>
#include <vector>
#include <string>

struct PublicParams {
    pairing_t pairing;

    element_t g;
    element_t h;

    element_t u;
    element_t v;

    element_t alpha;
    element_t gamma;

    int m;

    std::vector<element_t> D;
};

void setup_system(PublicParams &params, int rbits = 160, int qbits = 512);

#endif