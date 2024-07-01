#include "InputHandler.h"

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods, Game& game)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		game.Draw();
}
