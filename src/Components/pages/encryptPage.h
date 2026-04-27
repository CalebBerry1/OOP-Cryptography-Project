#pragma once

#include "../../core/CryptoService.h"
#include <QWidget>

class QTextEdit;
class QComboBox;

class EncryptPage : public QWidget {
    Q_OBJECT

    public: explicit EncryptPage(QWidget* parent = nullptr);

    signals: void backRequested();

    private slots:
        void onEncryptClicked();
        void onDecryptClicked();
        void onCopyClicked();
        void onClearClicked();

    private: 
        QTextEdit* inputField_;
        QTextEdit* outputField_;
        QComboBox* algorithmSelector_;
        CryptoService service_;

        Algorithm algorithmFromString(const QString& text);
};