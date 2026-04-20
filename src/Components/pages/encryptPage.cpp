#include "encryptPage.h"
#include "../../domain/CryptoModels.h"
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
#include <QClipboard>
#include <QGuiApplication>
#include <QDebug>

EncryptPage::EncryptPage(QWidget* parent) : QWidget(parent) {

    qDebug() << "[EncryptPage] Initializing";

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
    auto* copyButton = new QPushButton("Copy", this);
    auto* clearButton = new QPushButton("Clear", this);

    encryptButton -> setMinimumHeight(40);
    encryptButton -> setStyleSheet(AppStyles::primaryButton());

    decryptButton -> setMinimumHeight(40);
    decryptButton -> setStyleSheet(AppStyles::primaryButton());

    backButton -> setMinimumHeight(40);
    backButton -> setStyleSheet(AppStyles::ghostButton());

    copyButton -> setMinimumHeight(40);
    copyButton -> setStyleSheet(AppStyles::primaryButton());

    clearButton -> setMinimumHeight(40);
    clearButton -> setStyleSheet(AppStyles::ghostButton());
    

    auto* buttonRow = new QHBoxLayout();
    buttonRow -> setSpacing(12);
    buttonRow -> addWidget(backButton);
    buttonRow -> addWidget(clearButton);
    buttonRow -> addStretch(0);
    buttonRow -> addWidget(copyButton);
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

    // --- CONNECTIONS ---
    connect(backButton, &QPushButton::clicked, this, &EncryptPage::backRequested);
    connect(encryptButton, &QPushButton::clicked, this, &EncryptPage::onEncryptClicked);
    connect(decryptButton, &QPushButton::clicked, this, &EncryptPage::onDecryptClicked);
    connect(copyButton, &QPushButton::clicked, this, &EncryptPage::onCopyClicked);
    connect(clearButton, &QPushButton::clicked, this, &EncryptPage::onClearClicked);

    qDebug() << "[EncryptPage] Ready";
}

Algorithm EncryptPage::algorithmFromString(const QString& text) {
    if (text == "XOR Stream Cipher") {
        return Algorithm::XorStream;
    }
    if (text == "Vigenere Cipher") {
        return Algorithm::Vigenere;
    }
    return Algorithm::Feistel;
}

void EncryptPage::onEncryptClicked() {
    try {
        qDebug() << "[EncryptPage] onEncryptClicked()";

        QString input = inputField_ -> toPlainText().trimmed();
        QString algorithm = algorithmSelector_ -> currentText();

        Algorithm algo = algorithmFromString(algorithm);

        CryptoRequest req;
        req.algorithm = algo;
        req.mode = CryptoMode::Encrypt;
        req.input = input.toUtf8();
        req.key = "";

        CryptoResult result = service_.execute(req);

        if (result.success) {
            outputField_ -> setPlainText(QString::fromUtf8(result.output));
        } else {
            outputField_ -> setPlainText("Error: " + result.errorMessage);
        }

        if (input.isEmpty()) {
            qDebug() << "[EncryptPage] Encrypt aborted - input is empty";
            outputField_ -> setPlainText("Please enter some text to encrypt.");
            return;
        }

        qDebug() << "[EncryptPage] Encrypting with algorithm:" << algorithm;

        // Dummy output - replace with real cipher logic later
        // Idea: makes a CryptoRequest with the algorithm, mode, input, and key, passes it to service?
        // service goes and makes and performs encryption algorithm, comes back with algorithm results?
        outputField_ -> setPlainText("ENCRYPTED[" + algorithm + "]: Wq7#mZ2$kLp!9vNx");
    } catch (const std::exception& e) {
        qDebug() << "[EncryptPage] onEncryptClicked() exception:" << e.what();
    }
}

void EncryptPage::onDecryptClicked() {
    try {
        qDebug() << "[EncryptPage] onDecryptClicked()";

        QString input = inputField_ -> toPlainText().trimmed();
        QString algorithm = algorithmSelector_ -> currentText();

        if (input.isEmpty()) {
            qDebug() << "[EncryptPage] Decrypt aborted - input is empty";
            outputField_ -> setPlainText("Please enter some text to decrypt.");
            return;
        }
        
        qDebug() << "[EncryptPage] Decrypting with algorithm:" << algorithm;

        // Dummy output - replace with real cipher logic later
        outputField_ -> setPlainText("DECRYPTED[" + algorithm + "]: Hello, world!");
        

        } catch (const std::exception& e) {
        qDebug() << "[EncryptPage] onDecryptClicked() exception:" << e.what();

    }
}

void EncryptPage::onCopyClicked() {
    try {
        qDebug() << "[EncryptPage] onCopyClicked()";

        QString output = outputField_ -> toPlainText();

        if (output.isEmpty()) {
            qDebug() << "[EncryptPage] Copy aborted - output is empty";
            return;
        }

        QGuiApplication::clipboard() -> setText(output);
        qDebug() << "[EncryptPage] Output copied to clipboard";
    } catch (const std::exception& e) {
        qDebug() << "[EncryptPage] onCopyClicked() exception:" << e.what();
    }
}

void EncryptPage::onClearClicked() {
    try {
        qDebug() << "[EncryptPage] onClearClicked()";
        inputField_ -> clear();
        outputField_ -> clear();
        qDebug() << "[EncryptPage] Fields cleared";
    } catch (const std::exception& e) {
        qDebug() << "[EncryptPage] onClearClicked() exception:" << e.what();
    }
}