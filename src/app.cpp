#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // If your file is qml/Main.qml in qt_add_qml_module:
    engine.loadFromModule("CryptographyProject", "Main");
    
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}