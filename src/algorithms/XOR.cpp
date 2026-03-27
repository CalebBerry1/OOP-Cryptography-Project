// the XOR cipher takes an input target string, generates a random key, then uses the key to encrypt the target
// PHASE 1: Convert target to binary
// PHASE 2: Generate random integer for key then convert to binary 
// PHASE 3: Apply each bit of the key to each bit of the target to get a new binary result
// PHASE 4: Convert new binary result to plaintext. This is the encrypted result
// NOTE: Unless we can find a better way, the only current way to randomize/"reroll" the key is to specify a seed for the key generator

#include <iostream>
#include <random>
#include <bitset>
#include <string>

class XOR {
public:
    std::string targetOriginal;
    std::vector<std::bitset<8>> targetBinary;
    int keyCharacter;
    std::vector<int> keyInts;
    std::vector<std::bitset<8>> keyBytes;
    std::vector<std::bitset<8>> resultBinary;
    std::vector<std::string> resultPlaintext;
    int byteToInt;
    std::string result;
    int indexBytes = 0;
    int indexBits = 7;

    // NOTE: any reference to a bitset in this program should be 8 bits/1 byte
    int main() {

        // gets user input for the target message
        std::cout << "Enter your target message to encrypt:\n";
        std::getline(std::cin, targetOriginal); // getline() is necessary in order to read whitespaces the user enters

        // converts target message to binary
        // iterates through each character, converting it into 8 bits (1 byte)
        for (char c : targetOriginal) {

            // PHASE 1: converts the character into a byte
            std::bitset<8> byte(c);

            // adds the byte to targetBinary, which is the target message but in binary
            // targetBinary is a vector of bitsets, with each bitset being 1 character of the message
            targetBinary.push_back(byte);

            // PHASE 2: generates random integer as key for each character, converts keyCharacter to binary
            // for random number between 0 and n, do "rand() % (n+1)"
            // because we're working with 8 bits, we want anywhere from 0-255
            keyCharacter = rand() % (256);

            // adds the key for the current character to the total key vector
            keyInts.push_back(keyCharacter);

        }

        // once the message has been converted to binary, now creates a copy of it for the results
        resultBinary = targetBinary;

        // at this point, the key is a vector of integers (keyInts). this will turn each integer into a binary byte (keyBytes)
        for (int i : keyInts) {
            std::bitset<8> byte(i);
            keyBytes.push_back(byte);
        }


        // PHASE 3: uses an index variable to now finally perform the encryption
        // NOTE: indexBytes iterates through the vector of bytes, from 0 to 7
        // indexBits iterates the bits in a byte from 7 to 0 because by default it works right to left. going 7 to 0 works left to right
        // iterates through each byte
        while (indexBytes < (targetOriginal.size())) {

            // iterates through each bit, of each byte
            while (indexBits >= 0) {

                // looks at the active bit of the key. flips the corresponding bit if the key bit is a 1
                if (keyBytes[indexBytes][indexBits] == 1) {
                    resultBinary[indexBytes].flip(indexBits);
                }
                indexBits --;

            }

            indexBytes ++;
            indexBits = 7;
        }

        // PHASE 4: iterates through each encrypted byte and converts from binary to the encrypted plaintext
        for (std::bitset<8> byte : resultBinary) {

            // converts the byte from bitset to int, then char, then adds it to the encrypted message result
            byteToInt = byte.to_ulong();
            result += (static_cast<char>(byteToInt));
        }

        // DEBUG: prints the original target, key, and encrypted target all in binary, and the encrypted text result
        std::cout << "\nORIGINAL: \n";
        for (std::bitset<8> b : targetOriginal) {
            std::cout << b.to_string() << " ";
        }

        std::cout << "\nKEY: \n";
        for (std::bitset<8> b : keyBytes) {
            std::cout << b.to_string() << " ";
        }

        std::cout << "\nENCRYPTED: \n";
        for (std::bitset<8> b : resultBinary) {
            std::cout << b.to_string() << " ";
        }

        std::cout << "\nENCRYPTED MESSAGE: \n" << result;

        return 0;
    }
};