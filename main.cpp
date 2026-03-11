#include <iostream>
#include "setup.h"
#include "keygen.h"
#include "encrypt.h"
#include "decrypt.h"

int main() {
    PublicParams pp;
    MasterKey msk;
    setup(pp, msk);

    SecretKey alice;
    keygen(alice, pp, msk, "alice");

    std::vector<std::string> S = {"alice"};

    Ciphertext ct;
    element_t K;
    encrypt(ct, pp, S, K);

    element_t Ki;
    decrypt(Ki, pp, ct, alice);

    std::cout << "Session key:\n";
    element_printf("%B\n", K);

    std::cout << "Partial decrypt:\n";
    element_printf("%B\n", Ki);

    return 0;
}
