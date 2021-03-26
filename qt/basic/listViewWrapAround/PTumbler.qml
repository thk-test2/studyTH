import QtQuick 2.15

PathView {
    id: control

    objectName: "HTumbler"
    readonly property string uiType: "TUMBLER"

    property var orientation: Qt.Horizontal
    property alias visibleItemCount: control.pathItemCount

    pathItemCount: count
    currentIndex: count - Math.ceil(pathItemCount/2) + 1

    delegate: Text {
        text: modelData
    }

    path: Path {
        startX: control.currentItem.width / 2
        startY: control.currentItem.height / 2 * -1

//        PathMultiline {
//            paths: [
//                [Qt.point(30, control.currentItem.height * 2),
//                 Qt.point(30, control.currentItem.height),
//                 Qt.point(30, contorl.currentItem.height * 2)
//                ]
//            ]
//        }

        PathLine {
            relativeX: 0
            y: control.currentItem.height * 2
        }
        PathLine {
            relativeX: 0
            y: control.currentItem.height
        }
        PathLine {
            relativeX: 0
            y: control.currentItem.height * 2
        }
    }
}
