import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        anchors.horizontalCenter: parent.horizontalCenter

        HText {
            text: "Default"
            font.pixelSize: 20
        }

        HText {
            text: "Roboto"
            font.family: "Roboto"
            font.pixelSize: 20
        }

        HText {
            text: "Roboto-Bold"
            font.family: "Roboto"
            font.weight: Font.Bold
            font.pixelSize: 20
        }

        HText {
            text: "Roboto-Thin"
            font.family: "Roboto"
            font.weight: Font.Thin
            font.pixelSize: 20
        }

        HText {
            text: "NotoSansKR"
            font.family: "NotoSansKR"
            font.pixelSize: 20
        }

        HText {
            text: "NotoSansKR-Thin"
            font.family: "NotoSansKR"
            font.weight: Font.Thin
            font.pixelSize: 20
        }
    }
}
