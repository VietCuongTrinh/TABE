#include "setup.h"

void Setup(PublicParams &param, MasterKey &msk, int n, int m) {

    pbc_param_t pbc_param;
    pbc_param_init_a_gen(pbc_param, 160, 512);

    pairing_init_pbc_param(param.pairing, pbc_param);

    element_init_G1(param.g, param.pairing);
    element_init_G2(param.ge, param.pairing);
    element_init_Zr(msk.alpha, param.pairing);

    element_random(param.g);
    element_random(param.ge);
    element_random(msk.alpha);

    element_init_G1(param.g_alpha, param.pairing);
    element_pow_zn(param.g_alpha, param.g, msk.alpha);

    param.ge_alpha_powers.resize(2*n*m+1);

    for(int i=0;i<=2*n*m;i++){
        element_init_G2(param.ge_alpha_powers[i], param.pairing);
    }

    element_t tmp;
    element_init_Zr(tmp, param.pairing);
    element_set1(tmp);

    for(int i=0;i<=2*n*m;i++){

        element_pow_zn(param.ge_alpha_powers[i], param.ge, tmp);
        element_mul(tmp,tmp,msk.alpha);
    }

}