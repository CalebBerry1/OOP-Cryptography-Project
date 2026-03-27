// makeStringToBinary(std::string input)
// takes input string, converts to binary, returns entire string, in binary, in output string

#include <iostream>
#include <string>
#include <bitset>

std::string makeStringToBinary(std::string input) {
    std::string result;

    for (char c : input) {
        std::bitset<8> byte(c);

        result += byte.to_string();
    }
    
    return result;


}