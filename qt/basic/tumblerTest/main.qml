import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListViewTumbler {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 20
        model: 10
        //        orientation: ListViewTumbler.Horizontal

    }

    MyTumbler {
        anchors.centerIn: parent
        model: 10
    }

    CustomTumbler {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        model: 10
    }


//    PathViewTumbler {
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.right: parent.right
//        model: 10
//    }
}
