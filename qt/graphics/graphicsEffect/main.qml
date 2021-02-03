import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12

Window {
    visible: true
    width: 300
    height: 300

    Image {
        id: bug
        source: "qrc:/bug.png"
        sourceSize: Qt.size(parent.width, parent.height)
        smooth: true
        visible: false
    }

    Image {
        id: mask
        source: "qrc:/butterfly.png"
        sourceSize: Qt.size(parent.width, parent.height)
        smooth: true
        visible: false
    }

    OpacityMask {
        anchors.fill: bug
        source: bug
        maskSource: mask
    }

    //        FastBlur {
    //            anchors.fill: bug
    //            source: bug
    //            radius: 32
    //        }
}
