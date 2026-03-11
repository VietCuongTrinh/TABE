#include "setup.h"

void setup(PublicParams &pp, MasterKey &msk) {
    char param_str[] =
        "type a\n"
        "q 87807107996633125224377819847540498158068831994142082\n"
        "h 12016012264891146079388821366740534204802954401251311\n"
        "r 730750818665451621361119245571504901405976559617\n"
        "exp2 159\n"
        "exp1 107\n"
        "sign1 1\n"
        "sign0 1\n";

    pairing_init_set_str(pp.pairing, param_str);

    element_init_G1(pp.g, pp.pairing);
    element_init_G2(pp.g_tilde, pp.pairing);
    element_init_G1(pp.g_alpha, pp.pairing);
    element_init_GT(pp.egg_P0, pp.pairing);

    element_init_Zr(msk.alpha, pp.pairing);

    element_random(pp.g);
    element_random(pp.g_tilde);
    element_random(msk.alpha);

    element_pow_zn(pp.g_alpha, pp.g, msk.alpha);
    element_pairing(pp.egg_P0, pp.g, pp.g_tilde);
}
