import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    CustomTumbler {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        model: 10
    }

    ListViewTumbler {
        anchors.centerIn: parent
        model: 10
        //        orientation: ListViewTumbler.Horizontal

    }

    MyTumbler {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        model: 10
        visibleItemCount: 5
    }


//    PathViewTumbler {
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.right: parent.right
//        model: 10
//    }
}
