#pragma once

#include <glad/glad.h>
#include <string>
#include <unordered_map>
#include "glm/glm.hpp"

#ifndef GLSL
#define GLSL(A) "#version 300 es\n" #A
#endif

//编译shader源码
static GLuint CompileShader(GLenum shaderType, const char* shaderSource);

//创建完整Shader
static GLuint CreateGPUProgram(const char* vsShaderSource, const char* fsShaderSource);

class Shader{
public:

    static Shader buildGPUProgram(std::string vertexShaderSrc , std::string fragShaderSrc);

    //使用shader
    void useShader();

    //
    void setUniformInt(std::string key , int value);

    void setUniformFloat(std::string key , float value);

    //设置三维向量
    void setUniformVec3(std::string key , float x , float y , float z);

    //设置二维向量
    void setUniformVec2(std::string key , float x , float y);

    //设置三维向量 
    //void setUniformVec3(std::string key ,glm::vec3 value);

    void setUniformBool(std::string key , bool value);
    
    int findUniformLocation(std::string key);

    void setUniformMat4(std::string key , glm::mat4 mat);

    void setUniformVec3(std::string key ,glm::vec3 value);

    //get programid
    inline unsigned int getProgramId(){
        return programId;
    }

protected:
    unsigned int programId;
    std::unordered_map<std::string , int> unifromLocs; //unifrom变量loccation
};
