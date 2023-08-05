#pragma once

#include <memory>
#include "Shader.h"
#include "App.h"
#include <vector>
#include <string>

class ShowImage{
private:
    App *mContext;

    float left = 0.0f;
    float top = 0.0f;
    float width = 0.0f;
    float height = 0.0f;

    float texCoords[6 * 2] = {
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f
    };
    
    float vertices[6 * 2] = {
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f
    };

    Shader shader;

    unsigned int vao;
    unsigned int vbo[2];

    unsigned int textureId = 0;
    
    //同一目录下所有的图片名称
    std::shared_ptr<std::vector<std::string>> mImageList = nullptr;
   
    std::string currentPath;
    int currentIndex = 0;
public:
    ShowImage(App *context);

    //
    void findImagesInSameDir(std::string path);

    void init();

    void reloadImage(std::string path);

    void renderImage();

    void free();    

    //载入下一张image
    void nextImage();

    //载入前一张image
    void previousImage();
};








