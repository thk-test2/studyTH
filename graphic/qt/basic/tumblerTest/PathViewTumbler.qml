import QtQuick 2.12
import QtQuick.Controls 2.12

//! [contentItem]
Tumbler {
    id: tumbler

    contentItem: PathView {
        id: pathView
        model: tumbler.model
        delegate: Rectangle {
//            rotation: orientation === PathViewTumbler.Vertical ? 0 : 90
            width: 100; height: 300
            border.width: 2
            Text {
                anchors.centerIn: parent
                font.pixelSize: 20
                text: modelData
            }
        }
        clip: true
        pathItemCount: tumbler.visibleItemCount + 1
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        dragMargin: width / 2

        path: Path {
            startX: pathView.width / 2
            startY: -pathView.delegateHeight / 2
            PathLine {
                x: pathView.width / 2
                y: pathView.pathItemCount * pathView.delegateHeight - pathView.delegateHeight / 2
            }
        }

        property real delegateHeight: tumbler.availableHeight / tumbler.visibleItemCount
    }
}
