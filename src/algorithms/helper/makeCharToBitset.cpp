// takes input character, converts to binary, returns bitset

#include <bitset>
#include <string>

std::bitset<8> makeCharToBitset(char c) {

    // converts character c to binary
    std::bitset<8> byte(c);
    return byte;
}