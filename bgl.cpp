
// Define these only in *one* .cc file.
#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
// #define TINYGLTF_NOEXCEPTION // optional. disable exception handling.
#include "tiny_gltf.h"


//////////////////////////////
#include <algorithm>
#include <íostream>
#include <vector>



class Mesh {}


void LoadMesh(const tinygltf::Mesh &mesh) {
    std::cout << "Loading " << mesh.name << std::endl;
    // TODO
}


std::vector<Mesh> LoadMeshes(const tinygltf::Model &model) {
    std::for_each(model.meshes.begin(), model.meshes.end(), [] (auto& mesh) { LoadMesh(); );
}

///////////////////////////////////+
///////////////////////////////////+
///////////////////////////////////+




std::vector<GLuint> LoadSampler(tinygltf::Sampler &sampler) {


}



bool LoadGLTFModel(const std::filesystem::path &path) noexcept {
    const std::string filename { path.string() };
    const std::string extension { path.extension() };

    tinygltf::Model model;
    std::string err;
    std::string warn;

    tinygltf::TinyGLTF loader;
    bool successful { false };
    void SetImageLoader(LoadImageDataFunction LoadImageData, void *user_data);

    try  {
        if (extension == "gltf")
            successful = loader.LoadASCIIFromFile(&model, &err, &warn, filename);
        else if (extension == "glb") {
            successful =  LoadBinaryFromFile(&model, &err, &warn, filename);
        }
    } catch (...) {
        successful = false;
    }

    if (!warn.empty()) {
        std::cout << "Warning: " << warn << std::endl;
    }
    if (!err.empty()) {
        std::cout << "Error: " << err << std::endl;
    }

    if (!successful) {
        return false;
    }

    return true;
}

//---------------------------------
#define TINYGLTF_NO_STB_IMAGE

bool LoadImage(tinygltf::Image *, const int, std::string *,
                                      std::string *, int, int,
                                      const unsigned char *, int,
                                      void *user_pointer)
                                
{

    // TODO
}


void LoadMaterial() {
    
    tinygltf::Material m;


    m.
}


GLuint LoadImage(const tinygltf::Image &image) {
    tinygltf::SetImageLoader(LoadImage);
    // TODO: create GL texture
    return 0;
}

using GLuint = int;

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

tinygltf::Buffer

namespace gl {

class Model {
    GLuint ibo;
    GLuint vbo;
    GLuint vao;

    Model(tinygltf::Model &model) {
    

        model.buffers;
    }


    void createVAO(tinygltf::Accessor accessor ) {
        accessor.componentType;  // C++ data type

        accessor.type;
        accessor.byteOffset
        accessor.count;


        glGenVertexArrays()
        
    }



};

}


void LoadModel(const std::filesystem::path &path) {

    tinygltf::Model model;
    if (!LoadGLTFModel(path, model)) {
        // TODO: error handling
        return EXIT_FAILURE;
    }


    std::vector<Texture> textures;
    std::vector<Image> images;
    std::vector<Sampler> samplers;




    std::vector<Accessor> accessors;

    std::vector<Buffer> buffers;
    std::vector<BufferView> bufferView

    std::vector<Material> materials;
    std::vector<Mesh> meshes;
    std::vector<Node> nodes;


    std::vector<Camera> cameras;
    std::vector<Scene> scenes;
    std::vector<Light> lights;
}


















void main() {
    
    LoadModel(path);


    return EXIT_SUCCESS;
}