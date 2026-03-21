#include "encryptPage.h"
#include "../buttons/PrimaryButton.h"
#include "../styles/AppStyles.h"
#include "../styles/AppColors.h"
#include "../styles/AppFonts.h"

#include <QLabel>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

EncryptPage::EncryptPage(QWidget* parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);
    layout -> setContentsMargins(24, 24, 24, 24);
    layout -> setSpacing(16);

    // --- TITLE ---
    auto* title = new QLabel("Encryption", this);
    title -> setAlignment(Qt::AlignCenter);
    title -> setStyleSheet(AppStyles::labelPrimary());

    // --- ALGORITHM SELECTOR ---
    algorithmSelector_ = new QComboBox(this);
    algorithmSelector_ -> addItems({"XOR Stream Cipher", "Vigenere Cipher", "Feistel Cipher"});
    algorithmSelector_ -> setStyleSheet(AppStyles::comboBox());

    // --- INPUT FIELD ---
    auto* inputLabel = new QLabel("Source Text", this);
    inputLabel -> setStyleSheet(AppStyles::labelSecondary());

    inputField_ = new QTextEdit(this);
    inputField_ -> setPlaceholderText("Enter text to encrypt...");
    inputField_ -> setFixedHeight(120);
    inputField_ -> setStyleSheet(AppStyles::inputField());
    inputField_ -> setGraphicsEffect(AppStyles::glowShadow(this));

    // --- OUTPUT FIELD ---
    auto* outputLabel = new QLabel("Output", this);
    outputLabel -> setStyleSheet(AppStyles::labelSecondary());

    outputField_ = new QTextEdit(this);
    outputField_ -> setPlaceholderText("Encrypted text will appear here...");
    outputField_ -> setFixedHeight(120);
    outputField_ -> setReadOnly(true);
    outputField_ -> setStyleSheet(AppStyles::inputField());
    outputField_ -> setGraphicsEffect(AppStyles::glowShadow(this));

    // --- BUTTONS ---
    auto* encryptButton = new QPushButton("Encrypt", this);
    auto* decryptButton = new QPushButton("Decrypt", this);
    auto* backButton = new QPushButton("Back", this);

    encryptButton -> setMinimumHeight(40);
    encryptButton -> setStyleSheet(AppStyles::primaryButton());

    decryptButton -> setMinimumHeight(40);
    decryptButton -> setStyleSheet(AppStyles::primaryButton());

    backButton -> setMinimumHeight(40);
    backButton -> setStyleSheet(AppStyles::ghostButton());

    auto* buttonRow = new QHBoxLayout();
    buttonRow -> setSpacing(12);
    buttonRow -> addWidget(backButton);
    buttonRow -> addStretch(0);
    buttonRow -> addWidget(decryptButton);
    buttonRow -> addWidget(encryptButton);

    // --- ASSEMBLE ---
    layout -> addWidget(title);
    layout -> addWidget(algorithmSelector_);
    layout -> addWidget(inputLabel);
    layout -> addWidget(inputField_);
    layout -> addWidget(outputLabel);
    layout -> addWidget(outputField_);
    layout -> addLayout(buttonRow);
    layout -> addStretch();

    connect(backButton, &QPushButton::clicked, this, &EncryptPage::backRequested);
}