#include "Game.h"
#include<GLFW/glfw3.h>
#include <iostream>



// runs when game object is created
Game::Game()
	:
	window()
{
}

//Called Initially before the game loop starts.
//Can be used for initializing variables and game attributes
void Game::Start(GLFWwindow* MWindow)
{
	window = MWindow;
}

//Called every frame inside the game loop, and dt is the deltatime.
//multiply dt to speed to standardize the speed
// update to update and modify the member variables
void Game::Update(double dt)
{
	//std::cout << dt <<" ";
	
	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_UP) && !(deltaLoc == DOWN))
	{
		deltaLoc = Location(0, -1);
	}
	else if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_DOWN) && !(deltaLoc == UP))
	{
		deltaLoc = Location(0, 1);
	}
	else if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_LEFT) && !(deltaLoc == RIGHT))
	{
		deltaLoc = Location(-1, 0);
	}
	else if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_RIGHT) && !(deltaLoc == LEFT))
	{
		deltaLoc = Location(1, 0);
	}
	accurateSnakeSpeed += snakeSpeed * dt;
	if (accurateSnakeSpeed >= 1) {
		accurateSnakeSpeed -= 1;

		if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_LEFT_CONTROL))
		{
			snake.Grow();
		}

		snake.MoveBy(deltaLoc);
	}
}

//Function to render the frame
void Game::Draw()
{
	gfx.DrawRect((int)x-1, (int)y-1, 800+1, 800+1, false, Color(255, 255, 255));
	snake.Draw();

}
