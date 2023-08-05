#include <iostream>

//glad一定要放在glfw头文件的上面
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <memory>
#include "App.h"
 

static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0 , 0 , width , height);
}

static void processInput(GLFWwindow *window , std::shared_ptr<App> app) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
		return;
    }

    app->processInput(window);
}

int main(int argc , char *argv[]) {
    if(argc < 2)
        return -1;

    std::string imagePath =  argv[1];

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
    
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //todo create instance
    std::shared_ptr<App> app = std::make_shared<App>(imagePath);

    GLFWwindow* window = glfwCreateWindow(app->screenWidth, app->screenHeight, "xxx", NULL, NULL);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    app->init();

    while (!glfwWindowShouldClose(window)) {
        processInput(window , app);

        app->tick();
        // std::cout << "tick" << std::endl;
        glfwSwapBuffers(window);
        glfwPollEvents();
    }//end while
    app->free();

	glfwTerminate();

    return 0;
}