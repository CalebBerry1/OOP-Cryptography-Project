// test file
#include <iostream>
#include <string>
#include <bitset>
#include "helper/makeStringToBinary.h"
#include "FeistelCipher.h"


// WORKFLOW: take string data and int key > converts each character to ASCII > increases ASCII value by key
// > converts new ascii value to binary in type string > append the string to string "output" and return it at the end
// OBJECTIVE: now that the data has been converted to binary, in type string, it needs to be split in half
// because the string consists of bytes, there's always an even number of bits in the string
// the first half of the string is indices 0 to (length/2 - 1), and the second half is indices length/2 to length - 1

std::string data = "0123456789";
std::string firstHalf;
std::string secondHalf;
int index = 0;
int main() {

    // collects the first half of data to "firstHalf"
    while (index < (data.length()/2) ) {
        firstHalf += data[index];
        index++;
    }

    // collects the second half of data to "secondHalf"
    while (index < (data.length())) {
        secondHalf += data[index];
        index++;
    }

    std::cout << "First half: " << firstHalf << "\n";
    std::cout << "Length: " << firstHalf.length() << "\n";
    std::cout << "Second half: " << secondHalf << "\n";
    std::cout << "Length: " << secondHalf.length() << "\n";

    return 0;
}