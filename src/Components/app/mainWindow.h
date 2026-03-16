#pragma once
#include <QMainWindow>

class QStackedWidget;
class HomePage;

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);

    private:
        QStackedWidget* stack_;
        HomePage* home_;

        void setupShortcuts();
        void applyStyle();
};