#include "primaryButton.h"

PrimaryButton::PrimaryButton(const QString& text, QWidget* parent) : QPushButton(text, parent) {
    setMinimumHeight(40);
    applyStyle();
}

void PrimaryButton::applyStyle() {
    setStyleSheet(R"(
        QPushButton {
            background-color: #2d6cdf;
            color: white;
            border-radius: 10px;
            padding: 8px 16px;
            font-weight: bold;
        }

        QPushButton:hover {
            background-color: #3b7cff;
        }

        QPushButton:pressed{
            background-color: #2457b8;
        }
    )");
}