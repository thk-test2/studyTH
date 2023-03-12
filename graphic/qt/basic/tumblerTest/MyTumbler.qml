import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.impl 2.12
import QtQuick.Templates 2.12 as T

T.Tumbler {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + leftPadding + rightPadding) || 60 // ### remove 60 in Qt 6
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + topPadding + bottomPadding) || 200 // ### remove 200 in Qt 6

    Component.onCompleted: {
        console.log(control.implicitWidth +", "+control.implicitHeight)
    }

//    rotation: -90

    property int delegateWidth: 80
    property int delegateHeight: 300 // What is the principle to decide the height of delegate?
    spacing: 100

    delegate: Rectangle {
        MouseArea {
            anchors.fill: parent
            onClicked: {
                control.spacing += 10
            }
        }

        implicitWidth: control.delegateWidth
        implicitHeight: control.delegateHeight
        color: "lightblue"
        border.width: 2
        Text {
//            rotation: 90
            anchors.centerIn: parent
            text: modelData
            color: control.visualFocus ? control.palette.highlight : control.palette.text
            font: control.font
            opacity: 1.0 - Math.abs(Tumbler.displacement) / (control.visibleItemCount / 2)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    contentItem: TumblerView {
        implicitWidth: control.delegateWidth
        implicitHeight: control.delegateHeight
        model: control.model
        delegate: control.delegate
        path: Path {
            startX: control.contentItem.width / 2 // +100
            startY: -control.contentItem.delegateHeight / 2 - control.spacing // spacing
            PathLine {
                x: control.contentItem.width / 2
                y: (control.visibleItemCount + 1) * control.contentItem.delegateHeight - control.contentItem.delegateHeight / 2
            }
        }

        property real delegateHeight: control.availableHeight / control.visibleItemCount
    }
}
