#include "encrypt.h"

void Encrypt(PublicParams &param,
             vector<vector<int>> S,
             vector<int> threshold,
             Ciphertext &ct)
{

    element_t s;
    element_init_Zr(s, param.pairing);
    element_random(s);
    element_init_G1(ct.C1, param.pairing);
    element_init_G2(ct.C2, param.pairing);
    element_t tmp;
    element_init_Zr(tmp, param.pairing);
    element_mul(tmp, s, param.g_alpha);
    element_pow_zn(ct.C1, param.g, tmp);
    element_neg(ct.C1, ct.C1);
    element_set1(tmp);
    for(auto &set : S){
        for(int Ai : set){
            element_t val;
            element_init_Zr(val, param.pairing);
            element_set_si(val, Ai);
            element_mul(tmp,tmp,val);
        }
    }
    element_pow_zn(ct.C2, param.ge, tmp);
    ct.S = S;
    ct.threshold = threshold;
}