#pragma once

#include "Shader.h"
#include <memory>
#include "glm/ext/matrix_clip_space.hpp"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

struct TextureInfo{
	int srcWidth;
	int srcHeight;
	int channel;
	GLuint textureId;
	unsigned char *data;
};

class ShowImage;

class App{
private:
    std::string mPath;

    bool isKeyLeftPressed = false;
    bool isKeyRightPressed = false;
public:
    App(std::string path): mPath(path){
        orthMatrix = glm::ortho(0.0f , static_cast<float>(screenWidth) , 0.0f , static_cast<float>(screenHeight));
    }

    int screenWidth = 1280;
    int screenHeight = 800;

    std::shared_ptr<ShowImage> showImage;

    virtual void init();

    virtual void tick();

    virtual void free();

    TextureInfo loadTexture(std::string path , bool releaseData);

    glm::mat4 orthMatrix;//正交视图 投影矩阵

    void processInput(GLFWwindow *window);

    void onKeyboardLeftClicked(); //键盘左箭头按键被按下

    void onKeyboardRightClicked();//键盘右箭头按键被按下
};

static std::string findDirectoryPath(std::string path){
    std::string directory;
    const size_t lastSlashIdx = path.rfind('/');
    if (std::string::npos != lastSlashIdx){
        directory = path.substr(0, lastSlashIdx);
    }
    return directory;
}

static bool stringStartWith(std::string str , std::string startStr){
    if(str.empty() && startStr.empty())
        return true;
    
    if(str.empty() || startStr.empty()){
        return false;
    }

    if(str.size() >= startStr.size()){
        int len = startStr.size();
        for(int i = 0 ; i < len; i++){
            if(str[i] != startStr[i])
                return false;
        }//end for i

        return true;
    }else{
        return false;
    }
}

static bool stringEndWith(std::string str , std::string endStr){
    if(str.empty() && endStr.empty())
        return true;
    
    if(str.empty() || endStr.empty()){
        return false;
    }
    
    if(str.size() >= endStr.size()){
        int len = endStr.size();
        int strLen = str.size();
        int endStrLen = endStr.size();
        for(int i = 1 ; i <= len ;i++){
            if(str[strLen - i] != endStr[endStrLen - i])
                return false;
        }//end for i

        return true;
    }else{
        return false;
    }
}








