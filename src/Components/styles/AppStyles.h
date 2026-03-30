#pragma once

#include "AppColors.h"
#include "AppFonts.h"

#include <QString>
#include <QGraphicsDropShadowEffect>
#include <QColor>

namespace AppStyles {
    // --- WINDOW ---
    inline QString window() {
        return QString(R"(
            QMainWindow {
                background-color: %1;
            }
            QWidget {
                background-color: %2;
            }
            )").arg(AppColors::windowBg, AppColors::widgetBg);
    }

    // --- LABELS ---
    inline QString labelPrimary() {
        return QString("color: %1; font-size: %2px; font-weight: %3; letter-spacing: %4px;")
            .arg(AppColors::textPrimary)
            .arg(AppFonts::size2xl)
            .arg(AppFonts::weightSemibold)
            .arg(AppFonts::trackingTight);
    }

    inline QString labelSecondary() {
        return QString("color: %1; font-size: %2px; font-weight: %3; letter-spacing: %4px;")
            .arg(AppColors::textSecondary)
            .arg(AppFonts::sizeSm)
            .arg(AppFonts::weightMedium)
            .arg(AppFonts::trackingWide);
    }

    // --- BUTTONS ---
    inline QString primaryButton() {
        return QString(R"(
            QPushButton {
                background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %1, stop:1 %2);
                color: %3;
                border: none;
                border-radius: 8px;
                padding: 8px 20px;
                font-size: %4px;
                font-weight: %5;
                letter-spacing: 1px;
            }
            QPushButton:hover {
                background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %6, stop:1 %2);
            }
            QPushButton:pressed {
                background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %7, stop:1 %8);
            }
            QPushButton:disabled {
                background: %9;
                color: %10;
            }
        )").arg(AppColors::primaryBase, AppColors::accentBase, AppColors::textInverse)
        .arg(AppFonts::sizeMd)
        .arg(AppFonts::weightBold)
        .arg(AppColors::vibrantPurple, AppColors::primaryPress, AppColors::primaryMuted, AppColors::primaryMuted, AppColors::textDisabled);
    }

    inline QString ghostButton() {
        return QString(R"(
            QPushButton {
                background-color: transparent;
                color: %1;
                border: 1px solid %2;
                border-radius: 8px;
                padding: 8px 20px;
                font-size: %3;
                font-weight: %4;
                letter-spacing: 1px;
            }
            QPushButton:hover {
                background-color: %5;
                border-color: %6;
                color: %7;
            }
            QPushButton:pressed {
                background-color: %8;
            }
        )").arg(AppColors::textSecondary, AppColors::borderDefault)
        .arg(AppFonts::sizeMd)
        .arg(AppFonts::weightMedium)
        .arg(AppColors::surfaceBg, AppColors::borderFocus, AppColors::textPrimary, AppColors::overlayBg);
    }

    // --- INPUT FIELD ---
    inline QString inputField() {
        return QString(R"(
            QTextEdit, QLineEdit {
                background-color: %1;
                color: %2;
                border: 1px solid %3;
                border-radius: 8px;
                padding: 10px 12px;
                font-size: %4px;
                font-family: %5;
                selection-background-color: %6;
            }
            QTextEdit:focus, QLineEdit:focus {
                border: 1px solid %7;
                background-color: %8;
            }
        )").arg(AppColors::surfaceBg, AppColors::textPrimary, AppColors::borderDefault)
        .arg(AppFonts::sizeMd)
        .arg(AppFonts::familyMono)
        .arg(AppColors::primaryMuted, AppColors::borderGlow, AppColors::overlayBg);
    }

    // --- COMBO BOX ---
    inline QString comboBox() {
        return QString(R"(
            QComboBox {
                background-color: %1;
                color: %2;
                border: 1px solid %3;
                border-radius: 8px;
                padding: 6px 12px;
                font-size: %4px;
                font-weight: 5;
            }
            QComboBox:hover {
                border-color: %6;
            }
            QComboBox::drop-down {
                border: none;
                width: 24px;
            }
            QComboBox QAbstractItemView {
                background-color: %7;
                color: %2;
                border: 1px solid %3;
                selection-background-color: %8;
                outline: none;
            }
        )").arg(AppColors::surfaceBg, AppColors::textPrimary, AppColors::borderDefault)
        .arg(AppFonts::sizeMd)
        .arg(AppFonts::weightMedium)
        .arg(AppColors::borderFocus, AppColors::surfaceBg, AppColors::primaryMuted);
    }

    // --- CARDS / PANELS ---
    inline QString card() {
        return QString (R"(
            QWidget {
                background-color: %1;
                border: 1px solid %2;
                border-radius: 12px;
            }
        )").arg(AppColors::surfaceBg, AppColors::borderSubtle);
    }

    // --- SHADOWS ---
    inline QGraphicsDropShadowEffect* dropShadow(QObject* parent = nullptr) {
        auto* shadow = new QGraphicsDropShadowEffect(parent);
        shadow -> setBlurRadius(20);
        shadow -> setOffset(0, 4);
        shadow -> setColor(QColor(0, 0, 0, 160));
        return shadow;
    }

    inline QGraphicsDropShadowEffect* glowShadow(QObject* parent = nullptr) {
        auto* shadow = new QGraphicsDropShadowEffect(parent);
        shadow -> setBlurRadius(30);
        shadow -> setOffset(0,0);
        shadow -> setColor(QColor(26, 111, 255, 100));
        return shadow;
    }
}