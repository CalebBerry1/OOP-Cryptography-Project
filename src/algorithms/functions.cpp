// contains functions necessary for the algorithms to operate
#include <iostream>
#include <bitset>

// stringToBinary() converts an input string into binary
std::string stringToBinary(std::string input) {
    for (char c : input) {

        // returns a bitset of 8 bits called byte, made from the character c
        std::bitset<8> byte(c);
    }
}