#pragma once

#include "../core/ICipher.h"

class XorStreamCipher : public ICipher {
    public:
        CryptoResult run(const CryptoRequest& req, ICryptoStepSink& sink) override {
            return CryptoResult{false, {}, "XorStreamCipher not yet implemented"};
        }
};