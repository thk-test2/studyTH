import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import com.remainList 1.0
import com.remainModel 1.0

Item {
    id: root

    Rectangle{

        anchors{
            fill: parent
//            topMargin: 100
//            bottomMargin: 100
//            leftMargin: 200
//            rightMargin: 200
        }
        radius: 5
        border.width: 1

        ColumnLayout{
            anchors {
                fill: parent
                margins: 30
            }

            Rectangle{
                Layout.preferredHeight: 50
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignTop
                Label{
                    text: "Log"
                    verticalAlignment: Label.AlignVCenter
                    height: parent.height
                }

                CustomBorder{
                    commonBorder: false
                    tBorderwidth: 0
                    lBorderwidth: 0
                    rBorderwidth: 0
                    bBorderwidth: 1
                    borderColor: "gray"

                }

                Rectangle{
                    anchors.right: parent.right
                    height: parent.height
                    width: 25
                    Label{
                        text: "x"
                        anchors.right: parent.right
                        font.pixelSize: 25
                        verticalAlignment: Label.AlignVCenter
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: root.visible = false
                        cursorShape: Qt.PointingHandCursor
                    }
                }
            }

            Label{
                text: "Log - 2021.Jan.1"
                Layout.preferredHeight: 40
                verticalAlignment: Label.AlignVCenter
            }

            Item{
                Layout.minimumHeight: 100
                Layout.minimumWidth: 1
            }

            ListView{
                id: listViewContainer
                Layout.fillWidth: true
                Layout.fillHeight: true
                model: logPageModel.oneItemPerPage

                delegate: RowLayout{
                    anchors.fill: parent

                    Item{
                        Layout.preferredWidth: 150
                    }

                    GridLayout{
                        rows: 3
                        columns: 2
                        rowSpacing: 30
                        columnSpacing: 50
                        Layout.alignment: Qt.AlignTop
                        Label{
                            text: "START TIME:"
                        }
                        Label{
                            text: startTime
                        }

                        Label{
                            text: "END TIME:"
                        }
                        Label{
                            text: endTime
                        }

                        Label{
                            text: "SURGEON:"
                        }
                        Label{
                            text: surgeonIdx
                        }
                    }

                    Item{
                        Layout.preferredWidth: 300
                    }

                    Rectangle{
                        id: toolInfoContainer
                        Layout.preferredHeight: 400
                        Layout.preferredWidth: 500
                        CustomBorder{
                            commonBorder: false
                            tBorderwidth: 0
                            lBorderwidth: 1
                            rBorderwidth: 0
                            bBorderwidth: 0
                            borderColor: "gray"
                        }


                        ListView{
                            id: listView
                            property  UseRemainModel remainMode: UseRemainModel{
                                list : UseRemainList{
                                    items: toolList
                                }
                            }
                            anchors {
                                fill: parent
                                leftMargin: 100
                            }
                            model: listView.remainMode
//                            model: toolList
                            delegate: Item{
                                width: 300
                                height: 50
                                Label{
//                                    text: toolList[index].toolIdx
                                    text: toolIdx
                                    anchors{
                                        left: parent.left
                                    }
                                }
                                Label{
                                    anchors{
                                        right: parent.right
                                    }

                                    text: remainCnt +"/" + total
                                }
                            }
                        }
                    }
                }
            }



            Item{
                Layout.fillHeight: true
                Layout.minimumHeight: 2
                Layout.minimumWidth: 1
            }

            Item{
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                Button{
                    text: qsTr("PREV")
                }

                Button{
                    text: qsTr("NEXT")
                    anchors.right: parent.right
                }
            }

        }
    }
}
