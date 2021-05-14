import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView{
        id: list_
        anchors.fill: parent
        model: myModel

        delegate: Component{
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                height: 30
                font.bold: true
                text: title + " - " + artistName
            }
        }
    }
}
