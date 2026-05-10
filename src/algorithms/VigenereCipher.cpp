#include "VigenereCipher.h"

#include <iostream>

using namespace std;

// Generate the 26x26 alphabetic grid
void VigenereCipher::buildGrid() {
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            grid[i][j] = 'A' + (i + j) % 26;
        }
        
    }
}

pair<int, int> VigenereCipher::convertToAscii(char p, char k) {
    char text_p = toupper(p);
    char text_k = toupper(k);

    int ascii_p = static_cast<int>(text_p);
    int ascii_k = static_cast<int>(text_k);

    return {ascii_p, ascii_k};
}

pair<int, int> VigenereCipher::findChar(char p, char k) {
    int colCoordinate, rowCoordinate = convertToAscii(p, k);

    return colCoordinate, rowCoordinate;
}

VigenereCipher::VigenereCipher() {
    buildGrid();
}

CryptoResult VigenereCipher::run(const CryptoRequest& req, ICryptoStepSink& sink) {
}