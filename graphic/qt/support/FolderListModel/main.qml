import QtQuick 2.15
import QtQuick.Window 2.15
import Qt.labs.folderlistmodel 2.15

Window {
    visible: true
    width: 640 * 2
    height: 480
    title: qsTr("Hello World")

    FolderListModel {
        id: folderModel
        nameFilters: ["*"]
        showDirsFirst: true
        folder: "file:///home/parallels"
    }

    ////////////////////////////////////////

    Component {
        id: rowDelegate
        Rectangle {
            width: 200
            height: 50
            color: 'yellow'

            Row {
                Text {// LGLabelB {
                    id: filename
                    text: fileName
                    font.pixelSize: 20
                    color: 'red'
                }
                Text {// LGLabelSB {
                    text: filePath
                    font.pixelSize: 20
                    color: 'green'
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log(fileUrl)
                    folderModel.folder = fileUrl
                }
            }
        }
    }

    ///////////////////////////////////////////////////

    ListView {
        id: listview
        anchors.fill: parent
        clip: true

        model: folderModel
        delegate: rowDelegate
    }
}
