#include <iostream>
#include <random>
#include <bitset>
#include <string>
#include "helper/makeCharToBitset.h"

class XOR {
std::string targetOriginal;
std::vector<std::bitset<8>> targetBinary;
int keyCharacter;
std::vector<int> keyInts;
std::vector<std::bitset<8>> keyBytes;
std::vector<std::bitset<8>> resultBinary;
std::vector<std::string> resultPlaintext;
int byteToInt;
std::string result;
int indexBytes = 0;
int indexBits = 7;
    public:
    void mainXOR();
};