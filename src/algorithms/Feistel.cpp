// the Feistel cipher
#include <iostream>
#include <bitset>
#include <string>
#include "helper/makeStringToBinary.h"

std::string input;
std::string output;
int ascii;

// round function example: convert data and key to ASCII, increase ASCII values by key
std::string roundFunction(std::string data, int key) {

    // iterates through each character in the data input, increasing its ASCII value by the key
    for (char c : data) {
        ascii = c;
        ascii += key;

        // converts the new character from int to binary
        output += makeStringToBinary(std::to_string(ascii));
    }

    return output;
}

int main() {
    std::cout << "Enter your message to encrpyt: \n";
    std::cin >> input;
    
    return 0;
}