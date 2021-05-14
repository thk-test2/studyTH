import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView{
        id: control
        anchors.fill: parent
        model: myModel

        delegate: Component{
            Text{
                anchors.horizontalCenter: parent.horizontalCenter
                height: 30
                font.bold: true
                visible: enable
                text: title + " - " + artistName
            }
        }
    }
    Component.onCompleted: {
        console.log(control.model.get(0).enable)
    }
}
