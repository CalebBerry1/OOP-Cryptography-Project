#pragma once

#include <memory>
#include <stdexcept>
#include "../domain/CryptoModels.h"
#include "ICipher.h"

// --- Exception for unrecognized algorithm values ---
class UnsupportedCipherException : public std::runtime_error {
    public:
        explicit UnsupportedCipherException(const QString& algorithm)
            : std::runtime_error("Unsupported cipher: " + algorithm.toStdString()) {}
};

// --- FACTORY ---
class CipherFactory {
    public:
        static std::unique_ptr<ICipher> create(Algorithm algorithm);
};