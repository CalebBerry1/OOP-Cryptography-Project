// test file
#include <iostream>
#include <string>
#include <bitset>
#include "helper/makeStringToBinaryString.h"
#include "FeistelCipher.h"
#include "helper/makeCharToBitset.h"


// OBJECTIVE: make the classes work
// create a test class, and make a sample dragon

std::string test = "Love";

int main() {

    for (char c : test) {
        std::bitset<8> byte(c);
        std::cout << byte << "\n";
    }
    return 0;
}