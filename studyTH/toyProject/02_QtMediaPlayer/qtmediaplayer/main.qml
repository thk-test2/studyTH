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

        Text {
            id: mediaList
            color: "lightgreen"
            width: 300
            height: 100
            text: "Initial"
        }

        MediaPlayer {
            id: mediaplayer
            onMediaListChanged: {
                mediaList.text = mediaplayer.mediaList
            }
        }

        TextField {
            text: mediaplayer.mediaName
            placeholderText: qsTr("Media name")
            anchors.centerIn: parent

            onTextChanged: {
                console.log(text)
                mediaplayer.mediaName = text
            }
        }

        Row {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                id: button1
                text: "Play"
                onClicked: {
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
