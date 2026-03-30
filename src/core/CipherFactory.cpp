#include "CipherFactory.h"
#include "../algorithms/XorStreamCipher.h"
#include "../algorithms/VigenereCipher.h"
#include "../algorithms/FeistelCipher.h"

std::unique_ptr<ICipher> CipherFactory::create(Algorithm algorithm) {
    switch (algorithm) {
        case Algorithm::XorStream:
            return std::make_unique<XorStreamCipher>();
        case Algorithm::Vigenere:
            return std::make_unique<VigenereCipher>();
        case Algorithm::Feistel:
            return std::make_unique<FeistelCipher>();
        default:
            throw UnsupportedCipherException(
                    QString("Unknown algorithm value: %1")
                    .arg(static_cast<int>(algorithm))
            );
    };
}