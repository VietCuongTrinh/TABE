#include "decrypt.h"

bool Decrypt(
    PublicParams &param,
    SecretKey &sk,
    Ciphertext &ct,
    vector<int> user_attr,
    element_t &K
){
    pairing_t pairing = param.pairing;
    element_init_GT(K, pairing);
    for(int j=0;j<ct.S.size();j++){
        vector<int> S = ct.S[j];
        int t = ct.threshold[j];
        vector<int> intersection;
        for(int a : user_attr){
            for(int b : S){
                if(a==b) intersection.push_back(a);
            }
        }
        if(intersection.size() < t)
            continue;
        intersection.resize(t);
        vector<element_t> Z;
        for(int Ai : intersection){
            element_t Zi;
            element_init_GT(Zi, pairing);
            element_t pairing_val;
            element_init_GT(pairing_val, pairing);
            element_pairing(pairing_val,
                            sk.D[Ai],
                            ct.C2);
            element_set(Zi, pairing_val);
            Z.push_back(Zi);
        }

        element_t Z_final;
        element_init_GT(Z_final, pairing);
        element_set1(Z_final);
        for(int i=0;i<t;i++){
            element_mul(Z_final, Z_final, Z[i]);
        }

        // compute session key
        element_t tmp;
        element_init_GT(tmp, pairing);
        element_pairing(tmp, ct.C1, param.ge);
        element_div(K, tmp, Z_final);
        return true;
    }
    return false;
}