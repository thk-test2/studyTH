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
        anchors.fill: parent
        //width: 640
        //height: 480
        color: "lightblue"

        Rectangle {
            color: "lightgreen"
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width / 4
            height: parent.height / 5

            Button {
                anchors.fill: parent
                id: mediaList
                text: mediaplayer.mediaList
            }
        }

        MediaPlayer {
            id: mediaplayer
            onMediaListChanged: {
                console.log("MediaList changed")
                mediaList.text = mediaplayer.mediaList
            }
            onMediaNameChanged: {
                console.log("Name changed")
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
