import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.VirtualKeyboard 2.1

Window {
    id: root
    width: 960// root.screen.width/2
    height: 540// root.screen.height/2
    visible: true
    title: qsTr("Hello World")
//    contentOrientation: Qt.PortraitOrientation
    contentOrientation: Qt.LandscapeOrientation

    property bool rotated: false//(root.width > root.height)
    Item {
        id: panel
        anchors.centerIn: parent
        width: root.rotated ? root.height : root.width
        height: root.rotated ? root.width : root.height
//        rotation: root.rotated? 90 : 0
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
//        InputPanel {
//            id: inputPanel
////            x: (parent.width - parent.height) / 2
////            y: (parent.width - parent.height) / 2 +
////               (Qt.inputMethod.visible ? parent.height - inputPanel.height : parent.height)
//            anchors.left: parent.left
//            anchors.right: parent.right
//            width: 480

//            onYChanged: {
//                console.log("onYChanged:", inputPanel.width, inputPanel.height, x, y,
//                            parent.width, parent.height, parent)
//            }
//        }
    }

//    Component.onCompleted: {
////        console.log("Component.onCompleted", root.parent)
//        console.log("Component.onCompleted", contentItem)
//        contentItem.rotation = 90
//    }
}
