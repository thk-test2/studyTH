import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.VirtualKeyboard 2.1

Window {
    id: root
    width: root.screen.width/2
    height: root.screen.height/2
    visible: true
    title: qsTr("Hello World")

    property bool rotated: (root.width > root.height)
    Item {
        id: panel
        anchors.centerIn: parent
        width: root.rotated ? root.height : root.width
        height: root.rotated ? root.width : root.height
        rotation: root.rotated? 90 : 0
        onWidthChanged: {
            console.log("parent:", rotation, width, height)
            console.log("appContainer:", appContainer.width, appContainer.height, appContainer.x, appContainer.y)
            console.log("inputPanel:", inputPanel.width, inputPanel.height, inputPanel.x, inputPanel.y)
        }

        TextField {
            id: appContainer
            text: "TextInput"
            font.pixelSize: 50
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            anchors.left: parent.left
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: inputPanel.top
            Rectangle {
                anchors.fill: parent
                color: "transparent"
                border.color: "red"
                border.width: 3
            }
        }
        InputPanel {
            id: inputPanel
            y: Qt.inputMethod.visible ? parent.height - inputPanel.height : parent.height
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }
}
