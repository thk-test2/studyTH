import QtQuick 2.12
import QtQuick.Window 2.12
import ccOS.GUI.Controls 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        id: listView
        width: 200
        height: 500
        delegate: testDelegate
        model: 20
    }

    Component {
        id: testDelegate
//        Rectangle {
//            width: 200
//            height: 100
//            border.width: 2
//            ImageButton {
//                id: button
//            }
//        }
        HButton {
            width: 200
            height: 100
            text: modelData
            textColor: "white"
        }
    }
}
