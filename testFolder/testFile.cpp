// test file
#include <iostream>
#include <string>
#include <bitset>
#include "helper/makeStringToBinaryString.h"
#include "FeistelCipher.h"


// OBJECTIVE: XOR the half of data given

char c = "k";

int main() {

    std::bitset<8> byte(c);
    std::cout << byte;

    return 0;
}