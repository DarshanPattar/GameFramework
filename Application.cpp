#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "Macros.h"
#include "Graphics.h"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(900, 900, "Game", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "ERROR!" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;


    Graphics gfx;
    

    while (!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT);




        Color c(100, 250, 100);

        gfx.PutPixel(100, 100, c);




        glfwSwapBuffers(window);

        glfwPollEvents();
    }


        glfwTerminate();
    
    return 0;
}