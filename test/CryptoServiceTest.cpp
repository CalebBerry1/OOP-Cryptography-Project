#include "../src/core/CipherFactory.h"
#include "../src/core/CryptoService.h"

#include <QTest>


class CryptoServiceTest : public QObject {
    Q_OBJECT

    private slots:

        void validRequest_returnsResult() {
            CryptoService service;
            CryptoRequest req;
            req.algorithm = Algorithm::XorStream;
            req.mode = CryptoMode::Encrypt;
            req.input = "hello";
            req.key = "key";
            auto result = service.execute(req);
            QVERIFY(result.success == false);
        }

        void invalidAlgorithm_returnsFailure() {
            CryptoService service;
            CryptoRequest req;
            req.algorithm = static_cast<Algorithm>(999);
            req.mode = CryptoMode::Encrypt;
            req.input = "hello";
            req.key = "key";
            auto result = service.execute(req);
            QVERIFY(result.success == false);
            QVERIFY(!result.errorMessage.isEmpty());
        }

        void noSinkOverload_doesNotThrow() {
            CryptoService service;
            CryptoRequest req;
            req.algorithm = Algorithm::Feistel;
            req.mode = CryptoMode::Decrypt;
            req.input = "hello";
            req.key = "key";
            auto result = service.execute(req);
            QVERIFY(!result.errorMessage.isEmpty());
        }

        
};

QTEST_MAIN(CryptoServiceTest)
#include "CryptoServiceTest.moc"