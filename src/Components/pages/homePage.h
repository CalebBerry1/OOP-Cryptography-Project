#pragma once

#include <QWidget>

class PrimaryButton;

class HomePage : public QWidget {
    Q_OBJECT

    public: explicit HomePage(QWidget* parent = nullptr);

    signals: void encryptRequested();
};