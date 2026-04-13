#pragma once

#include <bitset>
#include <string>
#include <vector>
#include <utility>
#include "../core/ICipher.h"
using namespace std;

class XorStreamCipher : public ICipher {
    public:
        CryptoResult run(const CryptoRequest& req, ICryptoStepSink& sink) override;
        pair<string, string> run(const string& block1, const string& block2);
    
    private:
        vector<bitset<8>> toBinary(const string& input);
        string fromBinary(const vector<bitset<8>>& binary);
        vector<bitset<8>> generateKey(int length);
        vector<bitset<8>> applyXor(
            const vector<bitset<8>>& input,
            const vector<bitset<8>>& key
        );
};