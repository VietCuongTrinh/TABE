#include "keygen.h"

void KeyGen(PublicParams &param,
            MasterKey &msk,
            vector<int> attributes,
            SecretKey &sk)
{

    element_t ru;
    element_init_Zr(ru, param.pairing);
    element_random(ru);
    for(int attr : attributes){
        element_t Ai;
        element_init_Zr(Ai, param.pairing);
        element_set_si(Ai, attr);
        element_t denom;
        element_init_Zr(denom, param.pairing);
        element_add(denom, msk.alpha, Ai);
        element_t inv;
        element_init_Zr(inv, param.pairing);
        element_invert(inv, denom);
        element_t exp;
        element_init_Zr(exp, param.pairing);
        element_mul(exp, ru, inv);
        element_t key;
        element_init_G1(key, param.pairing);
        element_pow_zn(key, param.g, exp);
        sk.D[attr] = key;
    }
}
