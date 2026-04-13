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
        CryptoResult run(const CryptoRequest& req, ICryptoStepSink& sink, const XorStreamCipher& XorObject);
    
    private:  
    string input;
    string output;
    string leftHalf;
    string rightHalf;
    int index = 0;
    int ascii;
    string roundFunction(string data, int key);
    void splitData(string data);
    void XORHalf(XorStreamCipher XorObject, string rightHalf, string leftHalf);
    pair<string, string> returnHalves();
};