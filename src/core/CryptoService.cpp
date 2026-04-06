#include "CryptoService.h"

#include <QDebug>

CryptoResult CryptoService::execute(const CryptoRequest& req, ICryptoStepSink& sink) {
    try {
        qDebug() << "[CryptoService] execute() called";

        auto cipher = CipherFactory::create(req.algorithm);

        qDebug() << "[CryptoService] Cipher created, running...";

        CryptoResult result = cipher -> run(req, sink);

        if (!result.success) {
            qDebug() << "[CryptoService] Cipher returned failure:" << result.errorMessage;
        } else {
            qDebug() << "[CryptoService] Cipher completed successfully";
        }

        return result;
    } catch (const UnsupportedCipherException& e) {
        qDebug() << "[CryptoService] Unsupported Cipher:" << e.what();
        return CryptoResult{false, {}, QString::fromStdString(e.what())};
    } catch (const std::exception& e) {
        qDebug() << "[CryptoService] Unexpected error:" << e.what();
        return CryptoResult{false, {}, QString::fromStdString(e.what())};
    }
}

CryptoResult CryptoService::execute(const CryptoRequest& req) {
    return execute(req, nullSink_);
}