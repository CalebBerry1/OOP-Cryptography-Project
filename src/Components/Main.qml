import QtQuick
import QtQuick.Controls
import QtQuick.Window

ApplicationWindow {
    id: root
    visible: true
    title: "OOP Cryptography Project"

    readonly property int availW: Screen.desktopAvailableWidth;
    readonly property int availH: Screen.desktopAvailableHeight;

    minimumWidth: Math.round(availW * 0.5)
    minimumHeight: Math.round(availH * 0.5)

    Rectangle {
        id: mainCard
        anchors.fill: parent
        anchors.margins: 16
        radius: 14
        color: "#11131C"
        border.width: 1
        border.color: "#24293a"

        Label {
            anchors.centerIn: parent
            text: "Hello, Qt/QML"
        }

        // StackView {
        //     id: stackView
        //     anchors.fill: parent
        //     anchors.margins: 16 
        // }
    }


Shortcut {
    sequences: ["F11"]
    onActivated: {
        root.visibility = (root.visibility === Window.FullScreen) ? Window.AutomaticVisibility : Window.FullScreen
    }
}

}
