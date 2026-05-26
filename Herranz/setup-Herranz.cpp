#include "setup.h"
#include <iostream>

void setup_system(PublicParams &params, int rbits, int qbits) {

    pbc_param_t par;
    pbc_param_init_a_gen(par, rbits, qbits);

    pairing_init_pbc_param(params.pairing, par);

    element_init_G1(params.g, params.pairing);
    element_init_G2(params.h, params.pairing);

    element_random(params.g);
    element_random(params.h);

    element_init_Zr(params.alpha, params.pairing);
    element_init_Zr(params.gamma, params.pairing);

    element_random(params.alpha);
    element_random(params.gamma);

    element_init_G1(params.u, params.pairing);

    element_t tmp;
    element_init_Zr(tmp, params.pairing);

    element_mul(tmp, params.alpha, params.gamma);

    element_pow_zn(params.u, params.g, tmp);

    element_init_GT(params.v, params.pairing);

    element_pairing(params.v, params.g, params.h);
    element_pow_zn(params.v, params.v, params.alpha);

    params.m = 10;

    for (int i = 0; i < params.m - 1; i++) {
        element_t d;
        element_init_Zr(d, params.pairing);
        element_random(d);
        params.D.push_back(d);
    }

    element_clear(tmp);

    pbc_param_clear(par);
}