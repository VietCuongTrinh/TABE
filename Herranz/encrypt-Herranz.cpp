#include "encrypt.h"

void encrypt(
    const PublicParams &params,
    const std::vector<UserKey*> &users,
    int threshold,
    Ciphertext &ct
) {

    element_t k;
    element_init_Zr(k, params.pairing);
    element_random(k);

    element_init_G1(ct.C1, params.pairing);
    element_init_G2(ct.C2, params.pairing);
    element_init_GT(ct.K, params.pairing);

    element_t exp;
    element_init_Zr(exp, params.pairing);

    element_mul(exp, params.alpha, params.gamma);
    element_mul(exp, exp, k);

    element_neg(exp, exp);

    element_pow_zn(ct.C1, params.g, exp);

    element_t poly;
    element_init_Zr(poly, params.pairing);

    element_set1(poly);

    for (auto u : users) {

        element_t tmp;
        element_init_Zr(tmp, params.pairing);

        element_add(tmp, params.gamma, u->x);

        element_mul(poly, poly, tmp);

        element_clear(tmp);
    }

    element_mul(poly, poly, params.alpha);
    element_mul(poly, poly, k);

    element_pow_zn(ct.C2, params.h, poly);

    element_pow_zn(ct.K, params.v, k);

    element_clear(poly);
    element_clear(exp);
    element_clear(k);
}