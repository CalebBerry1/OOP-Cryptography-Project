#include "XorStreamCipher.h"
#include <QDebug>
#include <cstdlib>

std::vector<std::bitset<8>> XorStreamCipher::toBinary(const std::string& input) {
    std::vector<std::bitset<8>> binary;
    for (char c : input) {
        binary.push_back(std::bitset<8>(c));
    }
    return binary;
}

std::vector<std::bitset<8>> XorStreamCipher::generateKey(int length) {
    std::vector<std::bitset<8>> key;
    for (int i = 0; i < length; i++) {
        key.push_back(std::bitset<8>(rand() % 256));
    }
    return key;
}

std::vector<std::bitset<8>> XorStreamCipher::applyXor(
    const std::vector<std::bitset<8>>& input,
    const std::vector<std::bitset<8>>& key)
{
    std::vector<std::bitset<8>> result = input;
    for (int indexBytes = 0; indexBytes < (int)input.size(); indexBytes++) {
        for (int indexBits = 7; indexBits >= 0; indexBits--) {
            if (key[indexBytes][indexBits] == 1) {
                result[indexBytes].flip(indexBits);
            }
        }
    }
    return result;
}

std::string XorStreamCipher::fromBinary(const std::vector<std::bitset<8>>& binary) {
    std::string result;
    for (const std::bitset<8>& byte : binary) {
        result += static_cast<char>(byte.to_ulong());
    }
    return result;
}

// overload 1 - takes one input, XORs it with a randomly generated key
CryptoResult XorStreamCipher::run(const CryptoRequest& req, ICryptoStepSink& sink) {
    try {
        qDebug() << "[XorStreamCipher] run() called";
        std::string input = req.input.toStdString();
        sink.onStep(CryptoStep{ StepType::Init, 0, req.input, "XOR cipher starting"});

        // Phase 1 - convert input to binary
        auto inputBinary = toBinary(input);
        sink.onStep(CryptoStep{ StepType::Transform, 0, req.input, "Input converted to binary"});

        // Phase 2 - generate key
        auto key = generateKey(input.size());
        sink.onStep(CryptoStep{ StepType::Transform, 1, req.input, "Key generated"});

        // Phase 3 - apply XOR
        auto resultBinary = applyXor(inputBinary, key);
        sink.onStep(CryptoStep{ StepType::Transform, 2, req.input,"XOR applied"});

        // Phase 4 - convert back to string
        std::string resultStr = fromBinary(resultBinary);
        QByteArray output = QByteArray::fromStdString(resultStr);

        sink.onStep(CryptoStep{ StepType::Complete, 0, output, "XOR cipher complete"});

        qDebug() << "[XorStreamCipher] Completed successfully";
        return CryptoResult{ true, output, ""};
    
    } catch (const std::exception& e) {
        qDebug() << "[XorStreamCipher] Error:" << e.what();
        return CryptoResult{ false, {}, QString::fromStdString(e.what())};
    }
}

// overload 2 - XORs block1 with block2
// block1 and block2 are supposed to be two halves of data input, for the FesitelCipher
std::string XorStreamCipher::run(const std::string& block1, const std::string& block2) {
    try {
        qDebug() << "[XorStreamCipher] run() called";
        std::string leftHalf = block1;
        std::string rightHalf = block2;
        //sink.onStep(CryptoStep{ StepType::Init, 0, message.input, "XOR cipher starting"});

        // Phase 1 - convert input to binary
        auto binaryLeft = toBinary(leftHalf);
        auto binaryRight = toBinary(rightHalf);
        //sink.onStep(CryptoStep{ StepType::Transform, 0, req.input, "Input converted to binary"});

        // Phase 2 - apply XOR
        auto encryptedLeft = applyXor(binaryLeft, binaryRight);
        //sink.onStep(CryptoStep{ StepType::Transform, 2, req.input,"XOR applied"});

        // Phase 3 - convert back to string
        std::string resultLeft = fromBinary(encryptedLeft);
        std::string resultRight = fromBinary(binaryRight);
        //QByteArray output = QByteArray::fromStdString(resultStr);

        //sink.onStep(CryptoStep{ StepType::Complete, 0, output, "XOR cipher complete"});

        qDebug() << "[XorStreamCipher] Completed successfully";
        return resultLeft, resultRight;
    
    } catch (const std::exception& e) {
        qDebug() << "[XorStreamCipher] Error:" << e.what();
        //return CryptoResult{ false, {}, QString::fromStdString(e.what())};
    }
}
