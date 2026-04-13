#include "../src/helpers/CryptoEngine.h"
#include "../src/domain/CryptoModels.h"

#include <QTest>
#include <QSignalSpy>

Q_DECLARE_METATYPE(CryptoResult)

class CryptoEngineTest : public QObject {
    Q_OBJECT

    private slots:

        void run_emitsFinished() {
            CryptoEngine engine;
            QSignalSpy spy(&engine, &CryptoEngine::finished);

            CryptoRequest req;
            req.algorithm = Algorithm::XorStream;
            req.mode = CryptoMode::Encrypt;
            req.input = "hello";
            req.key = "key";

            engine.run(req);

            QCOMPARE(spy.count(), 1);
        }

        void run_invalidAlgorithm_emitsFailedResult() {
            CryptoEngine engine;
            QSignalSpy spy(&engine, &CryptoEngine::finished);

            CryptoRequest req;
            req.algorithm = static_cast<Algorithm>(999);
            req.mode = CryptoMode::Encrypt;
            req.input = "hello";
            req.key = "key";

            engine.run(req);

            QCOMPARE(spy.count(), 1);
            CryptoResult result = spy.at(0).at(0).value<CryptoResult>();
            QVERIFY(!result.success);
            QVERIFY(!result.errorMessage.isEmpty());
        }
};

QTEST_MAIN(CryptoEngineTest)
#include "CryptoEngineTest.moc"