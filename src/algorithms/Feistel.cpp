// the Feistel cipher
#include <iostream>
#include <bitset>
#include <string>
#include "makeStringToBinary.cpp"

std::string input;
std::string output;

// round function example: convert data and key to ASCII, increase ASCII values by key
int roundFunction(std::string data, int key) {

    // iterates through each character in the data input, increasing its ASCII value by the key
    for (char c : data) {
        int answer = c;
        c += key;

        // converts the new character from int to binary
        output += makeStringToBinary(std::to_string(num));
    }

}

int main() {
    std::cout << "Enter your message to encrpyt: \n";
    std::cin >> input;
    
    return 0;
}