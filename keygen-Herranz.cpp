#include "keygen.h"

void keygen(const PublicParams &params, UserKey &user) {

    element_init_Zr(user.x, params.pairing);
    element_random(user.x);

    element_init_G1(user.usk, params.pairing);

    element_t denom;
    element_init_Zr(denom, params.pairing);

    element_add(denom, params.gamma, user.x);

    element_invert(denom, denom);

    element_pow_zn(user.usk, params.g, denom);

    element_clear(denom);
}