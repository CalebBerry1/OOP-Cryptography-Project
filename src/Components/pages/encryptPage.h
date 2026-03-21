#pragma once

#include <QWidget>

class QTextEdit;
class QComboBox;

class EncryptPage : public QWidget {
    Q_OBJECT

    public: explicit EncryptPage(QWidget* parent = nullptr);

    signals: void backRequested();

    private: 
        QTextEdit* inputField_;
        QTextEdit* outputField_;
        QComboBox* algorithmSelector_;
};