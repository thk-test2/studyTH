import QtQuick 2.15
import QtQuick3D

Node {
    id: tinker_obj


    Model {
        id: group_0_15277357
        source: "meshes/name.mesh"

        DefaultMaterial {
            id: color_15277357_material
//            lighting: DefaultMaterial.NoLighting
            diffuseColor: "#ffe91d2d"
        }
        materials: [
            color_15277357_material
        ]
    }
}
