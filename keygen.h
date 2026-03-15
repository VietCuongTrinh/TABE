#ifndef KEYGEN_H
#define KEYGEN_H

#include <string>
#include "setup.h"

void KeyGen(PublicParams &param,
            MasterKey &msk,
            vector<int> attributes,
            SecretKey &sk);

#endif
