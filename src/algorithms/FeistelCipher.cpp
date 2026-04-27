// the Feistel cipher
#include <iostream>
#include <bitset>
#include <string>
#include "helper/makeStringToBinaryString.h"
#include "FeistelCipher.h"
#include "XorStreamCipher.h"
#include <tuple>
#include <utility>
using namespace std;


// round function example: convert data and key to ASCII, increase ASCII values by key
string FeistelCipher::roundFunction(string data, int key) {
    string result;
    // iterates through each character in the data input, increasing its ASCII value by the key
    for (char c : data) {
        ascii = c;
        ascii += key;
        result += static_cast<char>(ascii);
        // output is a member variable that is appended here, but was never cleared between calls
        // ended up bleeding into the final result, this fixes it
        // it wasn't needed for this function
    }

    return result;
}

// function to split the data input into two halves, assigning the halves to "leftHalf" and "rightHalf"
void FeistelCipher::splitData(string data) {

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
void FeistelCipher::XORHalf(string inputLeft, string inputRight) {

    // assigns the new leftHalf and rightHalf values, after the XOR operation occurs
    tie(leftHalf, rightHalf) = xorCipher_.run(inputLeft, inputRight);
}

pair<string, string> FeistelCipher::returnHalves() {
    return {leftHalf, rightHalf};
}

// Feistel CryptoResult run function
CryptoResult FeistelCipher::run(const CryptoRequest& req, ICryptoStepSink& sink) {
    splitData(req.input.toStdString());
    string processedRight = roundFunction(rightHalf, req.key.toInt());
    XORHalf(leftHalf, processedRight);
    pair<string, string> resultPair = returnHalves();
    string resultString = resultPair.first + resultPair.second;
    QByteArray output = QByteArray::fromStdString(resultString);
    
    return CryptoResult{ true, output, ""};
}
