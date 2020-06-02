import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import qt.mediaplayer 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: root
        width: 640
        height: 480
        color: "lightblue"

        Row {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                text: "Play"
            }
            Button {
                text: "Stop"
            }
        }

        TextField {
            text: MediaPlayer.userName
            placeholderText: qsTr("User name")
            anchors.centerIn: parent

            onTextChanged: MediaPlayer.userName = text
        }
    }
}
