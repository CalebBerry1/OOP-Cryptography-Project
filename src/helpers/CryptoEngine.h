#pragma once

#include "../domain/CryptoModels.h"
#include "../domain/CryptoStep.h"
#include "../core/ICryptoStepSink.h"
#include "../core/CryptoService.h"

#include <QObject>

class CryptoEngine : public QObject, public ICryptoStepSink {
    Q_OBJECT

    public:
        explicit CryptoEngine(QObject* parent = nullptr);

    public slots:
        void run(const CryptoRequest& request);
    
    signals:
        void stepGenerated(const CryptoStep& step);
        void finished(const CryptoResult& result);
    
    private:
        CryptoService service_;
        void onStep(const CryptoStep& step) override;
};