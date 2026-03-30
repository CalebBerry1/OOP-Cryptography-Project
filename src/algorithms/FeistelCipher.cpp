// the Feistel cipher
#include <iostream>
#include <bitset>
#include <string>
#include "helper/makeStringToBinaryString.h"
#include "FeistelCipher.h"


// round function example: convert data and key to ASCII, increase ASCII values by key
std::string FeistelCipher::roundFunction(std::string data, int key) {

    // iterates through each character in the data input, increasing its ASCII value by the key
    for (char c : data) {
        ascii = c;
        ascii += key;

        // converts the new character from int to binary
        output += makeStringToBinary(std::to_string(ascii));
    }

    return output;
}

// function to split the data input into two halves, assigning the halves to "leftHalf" and "rightHalf"
void FeistelCipher::splitData(std::string data) {

    // collects the first half of data to "leftHalf"
    while (index < (data.length()/2) ) {
        leftHalf += data[index];
        index++;
    }

    // collects the second half of data to "rightHalf"
    while (index < (data.length())) {
        rightHalf += data[index];
        index++;
    }
}

int main() {
    std::cout << "Enter your message to encrpyt: \n";
    std::cin >> input;
    
    return 0;
}