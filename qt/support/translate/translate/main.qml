import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        anchors.centerIn: parent
        Text {
            text: qsTr("new Text")
        }

        Text {
            text: qsTr("Taehyun")
        }
    }

    Component.onCompleted: {
        Qt.uiLanguage = "ko_KR"
    }
}
