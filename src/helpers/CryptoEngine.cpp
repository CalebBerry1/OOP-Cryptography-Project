#include "CryptoEngine.h"

CryptoEngine::CryptoEngine(QObject* parent) : QObject(parent) {}

void CryptoEngine::run(const CryptoRequest& request) {
    CryptoResult result = service_.execute(request, *this);
    emit finished(result);
}

void CryptoEngine::onStep(const CryptoStep& step) {
    emit stepGenerated(step);
}