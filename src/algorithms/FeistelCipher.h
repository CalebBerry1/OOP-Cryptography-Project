#pragma once

#include <bitset>
#include <string>
#include <vector>
#include "../core/ICipher.h"
#include "XorStreamCipher.h"
#include <tuple>
using namespace std;

class FeistelCipher : public ICipher {
    public:
        CryptoResult run(const CryptoRequest& req, ICryptoStepSink& sink) override;
    
    private:  
    string input;
    string output;
    string leftHalf;
    string rightHalf;
    int index = 0;
    int ascii;
    string roundFunction(string data, int key);
    void splitData(string data);
    void XORHalf(string rightHalf, string leftHalf);
    pair<string, string> returnHalves();
    XorStreamCipher xorCipher_;
};