#include "encrypt.h"

static void hash_to_Zp(element_t out, pairing_t pairing, const std::string &id) {
    element_from_hash(out, id.c_str(), id.length());
}

void encrypt(Ciphertext &ct,
             PublicParams &pp,
             const std::vector<std::string> &IDs,
             element_t session_key) {

    element_t s;
    element_init_Zr(s, pp.pairing);
    element_random(s);

    element_init_G1(ct.C1, pp.pairing);
    element_init_G2(ct.C2, pp.pairing);

    element_t tmp;
    element_init_G1(tmp, pp.pairing);

    element_pow_zn(tmp, pp.g_alpha, s);
    element_neg(ct.C1, tmp);

    element_pow_zn(ct.C2, pp.g_tilde, s);

    for (auto &id : IDs) {
        element_t h;
        element_init_Zr(h, pp.pairing);
        hash_to_Zp(h, pp.pairing, id);

        element_t mul;
        element_init_G2(mul, pp.pairing);
        element_pow_zn(mul, pp.g_tilde, h);

        element_mul(ct.C2, ct.C2, mul);

        element_clear(h);
        element_clear(mul);
    }

    element_init_GT(session_key, pp.pairing);
    element_pow_zn(session_key, pp.egg_P0, s);

    element_clear(tmp);
    element_clear(s);
}
