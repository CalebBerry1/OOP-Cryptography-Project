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

