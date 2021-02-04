import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

//import com.remainModel 1.0
//import com.remainList 1.0
//import com.remainPageModel 1.0
import com.logPageModel 1.0

Item {

    id: root
    property alias listView: listView
    property int totalPage: 0
    property int curPage: 0
    property int idx: 0

    property LogPageModel logPageModel: LogPageModel{}

    Rectangle{
        id: titleRect
        implicitWidth: parent.width
        implicitHeight: 40
        Item{
            anchors{
                margins: 10
                fill: parent
            }

            Label{
                anchors{
                    left: parent.left
                }
                text: qsTr("CSR SYSTEM LOG")
            }
            Label{
                anchors{
                    right: parent.right

                }
                text: logPageModel.currentPage + 1 + qsTr(" OF ") + logPageModel.pageCount
            }
        }
        CustomBorder
        {
            borderColor: "#32C9D9"
        }
    }

    Rectangle{
        id: contentRect
        anchors{
            left: titleRect.left
            right: titleRect.right
            top: titleRect.bottom
        }

        implicitWidth: parent.width
        implicitHeight: 400

        CustomBorder
        {
            borderColor: "#32C9D9"
        }

        ListView{
            id: listView
            model: 1

//            onCurrentIndexChanged: pageModel.currentPage = currentIndex


            anchors{
                margins: 10
                fill: parent
            }

            delegate: ColumnLayout{
                width: listView.width
                Repeater{
                    model: logPageModel.itemsForPage
//                    model: 5
                    ColumnLayout{
                        Rectangle{
                            Layout.preferredHeight: 30
                            Layout.minimumWidth: 50
                            Layout.fillWidth: true
                            Label{
                                anchors.fill: parent
                                id: contentLabel
                                text: "Log - " + startTime
//                                text: "Log - 1. Jan 2021"
                                wrapMode: Label.WordWrap
                                horizontalAlignment: Qt.AlignRight
                            }
                            MouseArea{
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                onClicked: popup.visible = true
                            }
                        }



                        Item {
                            Layout.columnSpan: 2
                            Layout.minimumWidth: 1
                            Layout.minimumHeight: 10
                        }
                    }
                }
            }
        }

        LogDetailListPopup{
            width: 1500
            height: 700


            id: popup
            z: 10
            visible: false
        }


        Timer{
            property int idx: 2
            interval: 1000
            repeat: true
            running: true
            onTriggered: {
//                pageModel.appendItemToList(idx, idx, idx, idx);
                idx++;
            }
        }



        Row{
            anchors{
                left: contentRect.left
                right: contentRect.right
                bottom: contentRect.bottom
                margins: 15
            }

            Button{
                text: qsTr("PREV")
                width: 120
                height: 30
                enabled: logPageModel.currentPage > 0
                onClicked: logPageModel.currentPage = Math.max(logPageModel.currentPage - 1, 0)
            }
            Item{
                width: 30
                height: 5
            }

            Button{
                text: qsTr("NEXT")
                width: 120
                height: 30
                enabled: logPageModel.currentPage < logPageModel.pageCount  - 1
                onClicked: logPageModel.currentPage = Math.min(logPageModel.currentPage + 1, logPageModel.pageCount)
            }
        }
    }
}
