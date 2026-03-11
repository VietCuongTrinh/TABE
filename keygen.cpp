#include "keygen.h"

static void hash_to_Zp(element_t out, pairing_t pairing, const std::string &id) {
    element_from_hash(out, id.c_str(), id.length());
}

void keygen(SecretKey &sk,
            PublicParams &pp,
            MasterKey &msk,
            const std::string &id) {

    sk.id = id;

    element_t h, denom, inv;
    element_init_Zr(h, pp.pairing);
    element_init_Zr(denom, pp.pairing);
    element_init_Zr(inv, pp.pairing);
    element_init_G1(sk.sk, pp.pairing);

    hash_to_Zp(h, pp.pairing, id);

    element_add(denom, msk.alpha, h);
    element_invert(inv, denom);

    element_pow_zn(sk.sk, pp.g, inv);

    element_clear(h);
    element_clear(denom);
    element_clear(inv);
}
