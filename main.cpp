#include <iostream>
#include <vector>
#include "setup.h"

using namespace std;

int main() {
    PublicParams param;
    MasterKey msk;
    int n = 5;
    int m = 2; 
    Setup(param, msk, n, m);
    vector<int> user_attributes = {1,2,3};
    SecretKey sk;
    KeyGen(param, msk, user_attributes, sk);
    vector<vector<int>> S;
    S.push_back({1,2,4});
    S.push_back({3,5,6});
    vector<int> threshold = {2,2};
    Ciphertext ct;
    Encrypt(param, S, threshold, ct);
    element_t K;
    bool ok = Decrypt(param, sk, ct, user_attributes, K);
    if(ok){
        cout << "Decryption success" << endl;
        element_printf("Session key: %B\n", K);
    }
    else{
        cout << "Decryption failed (threshold not satisfied)" << endl;
    }
    return 0;
}