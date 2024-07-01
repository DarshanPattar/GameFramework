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
	food.loc = Location(20, 20);
	food.c = Color(255, 255, 255);
}

//Called every frame inside the game loop, and dt is the deltatime.
//multiply dt to speed to standardize the speed
// update to update and modify the member variables
void Game::Update(double dt)
{
	//std::cout << dt <<" ";
	if (!GameOver) {
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
			if (snake.IsSegmentInTile(snake.GetNextHeadLocation(deltaLoc)) || !board.IsInBoard(snake.GetNextHeadLocation(deltaLoc))) {
				GameOver = true;
			}
			else {
				if (food.loc == snake.GetNextHeadLocation(deltaLoc))
				{
					food.isEaten = true;
					NetPoints += food.points;
					nFoodGoal += 1;
					snake.Grow();
					std::cout << NetPoints << " ";
				}

				snake.MoveBy(deltaLoc);
			}
		}
	}
	if (food.isEaten == true) {
		food.isEaten = false;
		Location newloc = Location(rand() % board.getGridWidth(), rand() % board.getGridHeight());
		while (snake.IsSegmentInTile(newloc)) {
			newloc = Location(rand() % board.getGridWidth(), rand() % board.getGridHeight());
		}
		food.loc = newloc;
		if (nFoodGoal == boostPointMark) {
			nFoodGoal = 0;
			food.points = 5;
			snakeSpeed += 1;
			food.c = Color(200, 0, 0);
		}
		else {
			food.points = 1;
			food.c = Color(255, 255, 255);
		}
	}
	
}

//Function to render the frame
void Game::Draw()
{
	if (GameOver) {
		gfx.DrawRect((int)x - 1, (int)y - 1, 800 + 1, 800 + 1, true, Color(255, 0, 0));
	}
	else {
		gfx.DrawRect((int)x - 1, (int)y - 1, 800 + 1, 800 + 1, false, Color(255, 255, 255));
		snake.Draw();
		food.Draw(board);
	}
}
