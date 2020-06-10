import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import io.qt.examples.mediaplayer 1.0

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

        MediaPlayer {
            id: mediaplayer
        }

        TextField {
            text: mediaplayer.userName
            placeholderText: qsTr("User name")
            anchors.centerIn: parent

            onTextChanged: mediaplayer.userName = text
        }

        Row {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                id: button1
                text: "Play"
                onClicked: {
                    //console.log(mediaplayer.userName)
                    mediaplayer.start()
                }
            }
            Button {
                text: "Stop"
                onClicked: {
                    mediaplayer.stop()
                }
            }
        }
    }
}
