#include "decrypt.h"

void share_decrypt(
    const PublicParams &params,
    const UserKey &user,
    const Ciphertext &ct,
    Share &share
) {

    element_init_GT(share.sigma, params.pairing);

    pairing_apply(
        share.sigma,
        user.usk,
        ct.C2,
        params.pairing
    );
}