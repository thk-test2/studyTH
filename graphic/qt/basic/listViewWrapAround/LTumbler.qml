import QtQuick 2.15

ListView {
    id: control

    objectName: "HTumbler"
    readonly property string uiType: "TUMBLER"

    property var orientation: Qt.Horizontal

    delegate: Text {
        text: modelData
    }
}
