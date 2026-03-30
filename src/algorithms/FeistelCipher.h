#pragma once

#include "../core/ICipher.h"

class FeistelCipher : public ICipher {
    public:
        CryptoResult run(const CryptoRequest& rec, ICryptoStepSink& sink) override {
            return CryptoResult{false, {}, "FeistelCipher is not yet implemented"};
        }
};