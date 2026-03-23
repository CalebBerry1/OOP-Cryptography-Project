#include "homePage.h"
#include "../styles/AppStyles.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

HomePage::HomePage(QWidget* parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);
    layout -> setContentsMargins(24, 24, 24, 24);
    layout -> setSpacing(16);

    auto* title = new QLabel("OOP Cryptography Project", this);
    title -> setAlignment(Qt::AlignCenter);
    title -> setStyleSheet("color: #e8ecf3; font-size: 22px; font-weight: 600;");

    auto* subtitle = new QLabel("Welcome to the Home Page", this);
    subtitle -> setAlignment(Qt::AlignCenter);
    subtitle -> setStyleSheet("color: #b8c1d1; font-size: 14px");

    auto* encryptButton = new QPushButton("Go to Encrypt Page", this);

    encryptButton -> setMinimumHeight(40);
    encryptButton -> setStyleSheet(AppStyles::primaryButton());

    layout -> addStretch();
    layout -> addWidget(title);
    layout -> addWidget(subtitle);
    layout -> addWidget(encryptButton, 0, Qt::AlignCenter);

    connect(encryptButton, &QPushButton::clicked, this, &HomePage::encryptRequested);
}