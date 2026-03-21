#include "mainWindow.h"
#include <QStackedWidget>
#include <QShortcut>
#include <QGuiApplication>
#include <QScreen>
#include <QKeySequence>

#include "../pages/homePage.h"
#include "../pages/encryptPage.h"
#include "AppStyles.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("OOP Cryptography Project");

    const QRect avail = QGuiApplication::primaryScreen()->availableGeometry();
    setMinimumSize(qRound(avail.width() * 0.5), qRound(avail.height() * 0.5));

    stack_ = new QStackedWidget(this);
    setCentralWidget(stack_);

    home_ = new HomePage(stack_);
    encrypt_ = new EncryptPage(stack_);

    stack_ -> addWidget(home_);
    stack_ -> addWidget(encrypt_);

    connect(home_, &HomePage::encryptRequested, this, [this]() {
        stack_ -> setCurrentWidget(encrypt_);
    });
    connect(encrypt_, &EncryptPage::backRequested, this, [this]() {
        stack_ -> setCurrentWidget(home_);
    });

    
    setupShortcuts();
    applyStyle();
}

void MainWindow::setupShortcuts() {
    auto* fs = new QShortcut(QKeySequence(Qt::Key_F11), this);
    connect(fs, &QShortcut::activated, this, [this]() {
        isFullScreen() ? showNormal() : showFullScreen();
    });
}

void MainWindow::applyStyle() {
    setStyleSheet(AppStyles::window());
}
