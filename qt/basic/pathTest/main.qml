import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    visible: true
    width: 640
    height: 960
    title: qsTr("Hello World")

    PathView {
        anchors.fill: parent
        model: 12
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        pathItemCount: 7

        delegate: Loader {
            sourceComponent: PathView.isCurrentItem ? center : other
        }

        Component {
            id: center
            Rectangle {
                width: 100
                height: 120
                color: "transparent"
                border.color: "red"
                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 30
                    text: modelData
                }
            }
        }
        Component {
            id: other
            Rectangle {
                width: 100
                height: 60
                color: "transparent"
                border.color: "red"
                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 30
                    text: modelData
                }
            }
        }

        path: Path {
            startX: 120; startY: 0
            PathLine {
                relativeX: 0
                relativeY: 960
            }
            PathPercent { value: 1.0 }
        }
    }
}
