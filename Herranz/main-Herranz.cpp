#include <iostream>

#include "setup.h"
#include "keygen.h"
#include "encrypt.h"
#include "decrypt.h"

int main() {

    PublicParams params;

    setup_system(params);

    UserKey u1, u2, u3;

    keygen(params, u1);
    keygen(params, u2);
    keygen(params, u3);

    std::vector<UserKey*> users = {&u1, &u2, &u3};

    Ciphertext ct;

    encrypt(params, users, 2, ct);

    Share s1, s2;

    share_decrypt(params, u1, ct, s1);
    share_decrypt(params, u2, ct, s2);

    std::cout << "Herranz scheme" << std::endl;

    return 0;
}