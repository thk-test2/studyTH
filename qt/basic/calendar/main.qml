import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480

    Button {
        onClicked: {
            calendar.visible = true
        }
    }

    Calendar {
        id: calendar
        anchors.centerIn: parent
        visible: false
        onClicked: {
            console.log(calendar.selectedDate)
        }
    }
}
