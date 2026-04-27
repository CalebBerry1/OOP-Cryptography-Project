// contains functions necessary for the algorithms to operate
#include <iostream>
#include <bitset>
#include <string>

// stringToBinary() converts an input string into binary, returning a vector of bitsets (each a byte)
std::vector<std::bitset<8>> messageInBinary;
std::vector<std::bitset<8>> stringToBinary(std::string input) {
    for (char c : input) {

        // returns a bitset of 8 bits called byte, made from the character c
        std::bitset<8> byte(c);

        // adds the byte to the bitset vector 
    }
}