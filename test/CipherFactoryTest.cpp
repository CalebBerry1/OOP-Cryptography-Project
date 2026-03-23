#include <QtTest>
#include "../src/core/CipherFactory.h"

class CipherFactoryTest : public QObject {
    Q_OBJECT

    private slots:

        void xorStream_returnsValidPointer() {
            auto cipher = CipherFactory::create(Algorithm::XorStream);
            QVERIFY(cipher != nullptr);
        }

        void vigenere_returnsValidPointer() {
            auto cipher = CipherFactory::create(Algorithm::Vigenere);
            QVERIFY(cipher != nullptr);
        }

        void feistel_returnsValidPointer() {
            auto cipher = CipherFactory::create(Algorithm::Feistel);
            QVERIFY(cipher != nullptr);
        }

        void unsupportedAlgorithm_throwsException() {
            QVERIFY_THROWS_EXCEPTION(UnsupportedCipherException, CipherFactory::create(static_cast<Algorithm>(999)));
        }
};

QTEST_MAIN(CipherFactoryTest)
#include "CipherFactoryTest.moc"