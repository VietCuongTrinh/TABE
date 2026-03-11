#include "decrypt.h"

void decrypt(element_t Ki,
             PublicParams &pp,
             Ciphertext &ct,
             SecretKey &sk) {

    element_init_GT(Ki, pp.pairing);

    element_t e1, e2;
    element_init_GT(e1, pp.pairing);
    element_init_GT(e2, pp.pairing);

    element_pairing(e1, ct.C1, pp.g_tilde);
    element_pairing(e2, sk.sk, ct.C2);

    element_mul(Ki, e1, e2);

    element_clear(e1);
    element_clear(e2);
}
