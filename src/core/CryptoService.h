#pragma once

#include "ICipher.h"
#include "CipherFactory.h"
#include "../domain/CryptoModels.h"
#include "../domain/CryptoStep.h"

class CryptoService {
    public:
        CryptoResult execute(const CryptoRequest& req, ICryptoStepSink& sink);
        CryptoResult execute(const CryptoRequest& req);

    private:
        NullStepSink nullSink_;
};