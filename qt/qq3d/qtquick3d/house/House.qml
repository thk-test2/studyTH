import QtQuick 2.15
import QtQuick3D 1.15

Node {
    id: house_obj


    Model {
        id: group_0_4634441
        source: "meshes/group_0_4634441.mesh"

        DefaultMaterial {
            id: color_4634441_material
            lighting: DefaultMaterial.NoLighting
            diffuseColor: "#ff46b749"
        }
        materials: [
            color_4634441_material
        ]
    }

    Model {
        id: group_0_15277357
        source: "meshes/group_0_15277357.mesh"

        DefaultMaterial {
            id: color_15277357_material
            lighting: DefaultMaterial.NoLighting
            diffuseColor: "#ffe91d2d"
        }
        materials: [
            color_15277357_material
        ]
    }

    Model {
        id: group_0_16089887
        source: "meshes/group_0_16089887.mesh"

        DefaultMaterial {
            id: color_16089887_material
            lighting: DefaultMaterial.NoLighting
            diffuseColor: "#fff5831f"
        }
        materials: [
            color_16089887_material
        ]
    }
}
