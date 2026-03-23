#pragma once

#include <QByteArray>
#include <QString>

enum class StepType {
    Init,
    RoundStart,
    RoundEnd,
    Transform,
    Complete,
    Error,
};

struct CryptoStep {
    StepType type;
    int roundIndex;
    QByteArray state;
    QString message;
};