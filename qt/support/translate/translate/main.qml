import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import EnumLanguage 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        anchors.centerIn: parent
        Text {
            text: qsTr("new Text")
            font.pixelSize: 20
        }

        Text {
            text: qsTr("Taehyun")
            font.pixelSize: 20
        }
    }

    ComboBox {
        currentIndex: LanguageManager.language
        model: ["English", "한국어"]
        onActivated: {
            if(index == 0){
                LanguageManager.language = EnumLanguage.ENG
            }else{
                LanguageManager.language = EnumLanguage.KOR
            }
        }
    }
}
