import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml.Models 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var flagArray: ["A", "B", "C", "D"]
    property DelegateModel climateIconModel: DelegateModel {
        model: flagArray.length
        delegate: Rectangle {
            width: 100
            height: 100
            border.color: "red"
        }
    }
    onFlagArrayChanged: {
        console.log("onFlagArrayChanged")
    }

    Column {
        Repeater {
            model: climateIconModel
        }
    }

    Button {
        anchors.centerIn: parent
        width: 200
        height: 100
        text: "TEST"
        onClicked: {
            flagArray = ["D", "E"]
        }
    }
    color: "lightgreen"
}
