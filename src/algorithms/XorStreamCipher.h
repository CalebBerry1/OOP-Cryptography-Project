#pragma once

#include <bitset>
#include <string>
#include <vector>
#include "../core/ICipher.h"

class XorStreamCipher : public ICipher {
    public:
        CryptoResult run(const CryptoRequest& req, ICryptoStepSink& sink) override;
        CrpyoResult run(const CryptoRequest& block1, const CryptoRequest& block2, ICryptoStepSink& sink) override;
    
    private:
        std::vector<std::bitset<8>> toBinary(const std::string& input);
        std::string fromBinary(const std::vector<std::bitset<8>>& binary);
        std::vector<std::bitset<8>> generateKey(int length);
        std::vector<std::bitset<8>> applyXor(
            const std::vector<std::bitset<8>>& input,
            const std::vector<std::bitset<8>>& key
        );
};