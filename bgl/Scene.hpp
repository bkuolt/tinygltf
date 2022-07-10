#include "tiny_gltf.h"
#include <Windows.h>
#include <glew.h>
#include <gl/GL.h>



class Mesh : public tinygltf::Mesh {
    const tinygltf::Model& model;


    tinygltf::BufferView GetBufferView() {

    }


    CreateVao(tinygltf::BufferView)





    Mesh() {
^       // buffer

        this->primitives()

        get IBO 
        get VBO

    }


    //////
    std::map<int, GLuint>& vbos;

    int getVBO(tinygltf::Primitive primitive) {
        const std::map<int, GLuint> vbos;
      //  tinygltf::Accessor indexAccessor { GetIBOAccessor(primitive) };
        return vbos.at(indexAccessor.bufferView);
    }


    GLuint GetIndexBuffer() noexcept const {
        return {};  // TODO
    }

    tinygltf::Accessor GetIndexAccessor(const tinygltf::Primitive& primitive ) {
        const auto accessorIndex { primitive.indices };
        return model.accessors[accessorIndex];
    }

    void draw() const {
        for (tinygltf::Primitive& primitive : primitives) {
            tinygltf::Accessor indexAccessor { GetIndexAccessor(primitive) };

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GetIndexBuffer());
            glDrawElements(primitive.mode, indexAccessor.count,
                           indexAccessor.componentType,
                           (void*)indexAccessor.byteOffset);
        }

    }

}








////////////
//////////////////////////
//////////////////////////
//////////////////////////

void LoadCamera(tinygltf::Model::Camera c)  {

   // c.
}

void PrintStat() {
    
    std::cout << "#Lights:  " << model.lights.size();
    std::cout << "#Cameras: " << model.cameras.size();

    model.material.size();
}

void LaodScene() {
    PrintStat();

    tinygltf::Model model;

    LoadCameras(model.cameras);
    LoadLights();

    LoadMeshes();

    


}