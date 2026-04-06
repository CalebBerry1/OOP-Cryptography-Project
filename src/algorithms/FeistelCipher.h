#pragma once

#include <bitset>
#include <string>
#include <vector>
#include "../core/ICipher.h"
#include "XorStreamCipher.h"
#include <tuple>

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
    std::string roundFunction(std::string data, int key);
    void splitData(std::string data);
    void XORHalf(XorStreamCipher XorObject, std::string rightHalf, std::string leftHalf);
    void updateHalves(std::string oldLeft, std::string oldRight);
};