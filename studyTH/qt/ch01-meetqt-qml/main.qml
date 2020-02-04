import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Image {
        id: root
        source: "images/background.png"

        Image {
            id: pole
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            source: "images/pole.png"
        }

        Image {
            id: wheel
            anchors.centerIn: parent
            source: "images/pinwheel.png"
            Behavior on rotation {
                NumberAnimation {
                    duration: 250
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: wheel.rotation += 90
        }
    }

}
