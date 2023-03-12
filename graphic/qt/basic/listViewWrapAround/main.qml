import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 640
    height: 480*2
    color: "black"
    title: qsTr("Hello World")

    PTumbler {
        height: 400
        width: 100
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        orientation: Qt.Vertical
        model: 10
        visibleItemCount: 5
        delegate: Rectangle {
            width: 100
            height: 100
            color: "white"
            border.width: 2
            border.color: 'black'
            Text {
                anchors.centerIn: parent
                text: modelData
            }
        }
    }

    LTumbler {
        id: tumbler
        Rectangle {
            anchors.fill: parent
            color: "transparent"
            border.color: "red"
        }
        height: 400
        width: 100
        anchors.centerIn: parent
        orientation: Qt.Vertical
        model: circularModel
        spacing: 20
        preferredHighlightBegin: height / 2
        preferredHighlightEnd: height / 2
        highlightRangeMode: ListView.StrictlyEnforceRange
        Component.onCompleted: {

        }

        onCurrentIndexChanged: {
            console.log(currentIndex, model)

            for(var i = 0; i < 10; i++) {
                model.append(model.get(i))
            }

        }

        ListModel {
            id: circularModel
            ListElement { value: 0 }
            ListElement { value: 1 }
            ListElement { value: 2 }
            ListElement { value: 3 }
            ListElement { value: 4 }
            ListElement { value: 5 }
            ListElement { value: 6 }
            ListElement { value: 7 }
            ListElement { value: 8 }
            ListElement { value: 9 }
        }

        delegate: Rectangle {
            width: 100
            height: ListView.isCurrentItem ? 150 : 100
            color: tumbler.currentIndex === index ? "lightgreen" : "white"
            border.width: 2
            border.color: 'black'
            Text {
                anchors.centerIn: parent
                text: modelData
            }
        }
    }
}
