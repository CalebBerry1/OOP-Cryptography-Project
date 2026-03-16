#pragma once

#include <QPushButton>

class PrimaryButton : public QPushButton {
    Q_OBJECT
    public: explicit PrimaryButton(const QString& text, QWidget* parent = nullptr);

    private: void applyStyle();
};