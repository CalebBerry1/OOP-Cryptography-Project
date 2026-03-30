#pragma once
#include <QMainWindow>

class QStackedWidget;
class HomePage;
class EncryptPage;

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);

    private:
        QStackedWidget* stack_;
        HomePage* home_;
        EncryptPage* encrypt_;

        void setupShortcuts();
        void applyStyle();
};