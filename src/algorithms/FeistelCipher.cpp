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

// function to XOR the right half of data onto the left half
// the "XorStreamCipher XorObject" parameter requires the instantiated XOR object 
// we may need to overload the run function, because instead of generating a key to use for XOR, we need to use the
// right half as the key, and XOR it with the left half. but can keep existing run function as overlaoding example
// we could also make FeistelCipher a child class of XORCipher parent class
void FeistelCipher::XORHalf(XorStreamCipher XorObject, std::string rightHalf, std::string leftHalf) {
    XorObject.run()
}