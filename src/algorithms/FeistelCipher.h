#pragma once

#include <bitset>
#include <string>
#include <vector>
#include "../core/ICipher.h"

class FeistelCipher : public ICipher {
    public:
        CryptoResult run(const CryptoRequest& req, ICryptoStepSink& sink) override;
    
    private:  
    std::string input;
    std::string output;
    std::string leftHalf;
    std::string rightHalf;
    int index = 0;
    int ascii;
};