#pragma once

#include <QString>
#include "AppColors.h"
#include "AppFonts.h"

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
        return QString("color: %1; font-size: %2px; font-weight: %3;")
            .arg(AppColors::textPrimary)
            .arg(AppFonts::size2xl)
            .arg(AppFonts::weightSemibold);
    }

    inline QString labelSecondary() {
        return QString("color: %1; font-size: %2px;")
            .arg(AppColors::textSecondary)
            .arg(AppFonts::sizeMd);
    }

    // --- BUTTONS ---
    inline QString primaryButton() {
        return QString(R"(
            QPushButton {
                background-color: %1;
                color: %2;
                border-radius: 10px;
                padding: 8px 16px;
                font-size: %3px;
                font-weight: %4;
            }
            QPushButton:hover {
                background-color: %5;
            }
            QPushButton:pressed {
                background-color: %6;
            }
            QPushButton:disabled {
                background-color: %7;
                color: %8;
            }
        )").arg(AppColors::primaryBase, AppColors::textInverse)
        .arg(AppFonts::sizeMd)
        .arg(AppFonts::weightBold)
        .arg(AppColors::primaryHover, AppColors::primaryPress, AppColors::primaryMuted, AppColors::textDisabled);
    }

    // --- CARDS / PANELS ---
    inline QString card() {
        return QString (R"(
            QWidget {
                background-color: %1;
                border: 1px solid %2;
                border-radius: 12px;
            }
        )").arg(AppColors::surfaceBg, AppColors::borderDefault);
    }

    // --- INPUT FIELDS ---
    inline QString inputField() {
        return QString(R"(
            QLineEdit {
                background-color: %1;
                color: %2;
                border: 1px solid %3;
                border-radius: 8px;
                padding: 6px 12px;
                font-size: %4px;
            }
            QLineEdit:focus {
                border: 1px solid %5;
            }
            QLineEdit::placeholder {
                color: %6;
            }
        )").arg(AppColors::surfaceBg, AppColors::textPrimary, AppColors::borderDefault)
        .arg(AppFonts::sizeMd)
        .arg(AppColors::borderFocus, AppColors::textDisabled);
    }
}