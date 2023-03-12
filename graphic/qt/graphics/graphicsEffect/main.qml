import QtQuick 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.12

Window {
    visible: true
    width: 300
    height: 300
//    color: "black"

    Image {
        id: bug
        source: "qrc:/bug.png"
        sourceSize: Qt.size(parent.width, parent.height)
        smooth: true
        visible: false
    }

    Image {
        id: mask
        source: "images/fog.png"
        sourceSize: Qt.size(parent.width, parent.height)
        smooth: true
        visible: false
    }

    ThresholdMask {
        anchors.fill: bug
        source: bug
        maskSource: mask
        threshold: 0.4
        spread: 0.2
    }

//    Image {
//        id: mask
//        source: "qrc:/butterfly.png"
//        sourceSize: Qt.size(parent.width, parent.height)
//        smooth: true
//        visible: false
//    }

//    OpacityMask {
//        anchors.fill: bug
//        source: bug
//        maskSource: mask
//    }

//    Glow {
//        anchors.fill: mask
//        radius: 8
//        samples: 17
//        color: "white"
//        source: mask
//    }

    //    LevelAdjust {
    //        anchors.fill: mask
    //        source: mask
    //        minimumOutput: "#00ffffff"
    //        maximumOutput: "#ff000000"
    //    }

    //        FastBlur {
    //            anchors.fill: bug
    //            source: bug
    //            radius: 32
    //        }

//    Rectangle {
//        id: displacement
//        color: Qt.rgba(0.5, 0.5, 1.0, 1.0)
//        anchors.fill: parent
//        visible: false
//        Image {
//            anchors.centerIn: parent
//            source: "qrc:/glass_normal.png"
//            sourceSize: Qt.size(parent.width/2, parent.height/2)
//            smooth: true
//        }
//    }

//    Displace {
//        anchors.fill: bug
//        source: bug
//        displacementSource: displacement
//        displacement: 0.1
//    }
}
