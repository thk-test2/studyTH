import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
            id: rec_contents
            anchors.fill: parent
            ScrollView {
                anchors.fill: parent
                clip: true
                ScrollBar.vertical: ScrollBar {
                    interactive: true

                    anchors.right: parent.right
                    anchors.rightMargin: 36
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    padding: 0
                    width: 8
                    policy: ScrollBar.AlwaysOn
                    contentItem: Rectangle {
                        width: 8
                        radius: 5.5
                        border.width: 0
                        color: "#787e87"
                    }
                    background: Rectangle {
                        width: 8
                        color: "#d6d8db"
                        radius: 5.5
                    }
                }
                Column {
                    Rectangle {
                        width: rec_contents.width
                        height: 332
                        color: "blue"
                    }
                    Rectangle {
                        width: rec_contents.width
                        height: 332
                        color: "red"
                    }
                    Rectangle {
                        width: rec_contents.width
                        height: 416
                        color: "green"
                    }
                    Rectangle {
                        width: rec_contents.width
                        height: 332
                        color: "yellow"
                    }
                }
            }
        }
}
