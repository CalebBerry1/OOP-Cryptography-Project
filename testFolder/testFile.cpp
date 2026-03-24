// test file
#include <iostream>
#include <string>
#include <bitset>
#include "makeStringToBinary.cpp"

std::string data = "Hello";

// TESTING: converting input string to binary
// converts message to binary. now needs to store binary in a data type (string? vector?)
// once binary is stored, the algorithms need to access it to do the following:
//  * access each byte to XOR it with a key
//  * split all the bits in halves, even if it splits a byte in half, 
// if this returns a string, the XOR can just convert it to binary and it can be exactly split in half easily
int main() {
std::string answer;
int num = 6;
std::string result;

    for (char c : data) {
        std::bitset<8> byte(c);

        // adds the byte to a string
        answer += byte.to_string();

    }
    
    // converts int to string
    result += std::to_string(num);

    // converts integer value into binary equivalent, from type int to string
    std::cout << makeStringToBinary(std::to_string(num));


    return 0;
}