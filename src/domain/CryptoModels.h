#pragma once

#include <QByteArray>
#include <QString>

enum class Algorithm {
    XorStream,
    Vinegere,
    Feistel
};

enum class CryptoMode {
    Encrypt,
    Decrypt
};

struct CryptoRequest {
    Algorithm algorithm;
    CryptoMode mode;
    QByteArray input;
    QString key;
};

struct CryptoResult {
    bool success;
    QByteArray output;
    QString errorMessage;
};