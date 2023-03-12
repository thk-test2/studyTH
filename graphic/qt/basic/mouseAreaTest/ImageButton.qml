import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    id: button
    anchors.centerIn: parent
    color: "red"
    width: 50
    height: 50
    border.width: 2
    MouseArea {
//        preventStealing: true
        anchors.fill: button
        onClicked: {
            console.log("onClicked", mouseX, mouseY)
        }
        onPressed: {
            console.log("onPressed", mouseX, mouseY)
        }
        onReleased: {
            console.log("onReleased", mouseX, mouseY)
        }
    }
}
