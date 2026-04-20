#pragma once

#include "../core/ICipher.h"

class VigenereCipher : public ICipher {
    public:
        CryptoResult run(const CryptoRequest& req, ICryptoStepSink& sink) override {
            return CryptoResult{false, {}, "VigenereCipher is not yet implemented"};
        }
    
    private:
        char grid[26][26];
        void buildGrid();
};