#include "homePage.h"

#include <QLabel>
#include <QVBoxLayout>

#include "../components/buttons/PrimaryButton.h"

HomePage::HomePage(QWidgets* parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);
    layout -> setContentsMargins(24, 24, 24, 24);
    layout -> setSpacing(16);

    auto* title = new QLabel("OOP Cryptography Project", this);
    title -> setAlignment(Qt::AlignCenter);
    title -> setStyleSheet("color: #e8ecf3; font-size: 22px; font-weight: 600;");

    auto* subtitle = new QLabel("Welcome to the Home Page", this);
    subtitle -> setAlignment(QT::AlignCenter);
    subtitle -> setStyleSheet("color: #b8c1d1; font-size: 14px");

    auto* encryptButton = new PrimaryButton("Go to Encrypt Page", this);

    layout -> addStretch();
    layout -> addWidget(title);
    layout -> addWidget(subtitle);
    layout -> addWidget(encryptButton, 0, Qt::AlignCenter);

    connect(encryptButton, &QPushButton::clicked, this, &HomePage::encryptRequested);
}