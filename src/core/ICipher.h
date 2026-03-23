#pragma once

#include "../domain/CryptoModels.h"
#include "../domain/CryptoStep.h"

class ICryptoStepSink {
    public:
        virtual ~ICryptoStepSink() = default;
        virtual void onStep(const CryptoStep& step) = 0;
};

class NullStepSink : public ICryptoStepSink {
    public:
        void onStep(const CryptoStep&) override {}
};

class ICipher {
    public:
        virtual ~ICipher() = default;
        virtual CryptoResult run(const CryptoRequest& req, ICryptoStepSink& sink) = 0;
};