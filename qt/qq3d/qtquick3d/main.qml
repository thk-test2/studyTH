import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick3D 1.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    View3D {
        anchors.fill: parent

        Name {
            position: Qt.vector3d(0, 150, 0)
            scale: Qt.vector3d(2, 2, 2)
            eulerRotation: Qt.vector3d(-50, -20, 0)
        }

        House {
            position: Qt.vector3d(0, 0, 0)
            scale: Qt.vector3d(4, 4, 4)
            eulerRotation: Qt.vector3d(-100, -20, 0)
        }

        environment: SceneEnvironment {
            clearColor: "skyblue"
            backgroundMode: SceneEnvironment.Color
        }

        PerspectiveCamera {
            position: Qt.vector3d(0, 200, 300)
            eulerRotation.x: -30
        }

        DirectionalLight {
            eulerRotation.x: -30
            eulerRotation.y: -70
        }
    }
}
