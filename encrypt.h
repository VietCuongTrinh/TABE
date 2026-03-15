#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <vector>
#include <string>
#include "setup.h"

void Encrypt(PublicParams &param,
             vector<vector<int>> S,
             vector<int> threshold,
             Ciphertext &ct);

#endif
