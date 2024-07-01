#pragma once

#include <GLFW/glfw3.h>
#include "Game.h"

class Input {
public:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods, Game& game = Game());
};