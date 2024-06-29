#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "Macros.h"
#include "Graphics.h"
#include "Game.h"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(SCREENWIDTH, SCREENHEIGHT, "Game", NULL, NULL);
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
    {

        Graphics gfx;
        Game game;

        double currentTime = glfwGetTime();
        double lastFrame = currentTime;
        double deltaTime;

        game.Start();
        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            currentTime = glfwGetTime();
            deltaTime = currentTime - lastFrame;

            game.Update(deltaTime);
            game.Draw();


            lastFrame = currentTime;

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    glfwTerminate();
    
    return 0;
}