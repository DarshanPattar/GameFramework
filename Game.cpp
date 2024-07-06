#include "Game.h"
#include<GLFW/glfw3.h>
#include <iostream>



// runs when game object is created
Game::Game()
	:
	window(),
	rng(std::random_device()())
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
	switch (gameState)
	{
	case TITLE:
		//Press enter to start playing the game.
		if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ENTER))
		{
			gameState = GAME;
			gameOver = false;
			Reset();
		}
		break;
	case GAME:
		if (!gameOver) {
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
					gameOver = true;
					gameState = GAMEOVER;
				}
				else {
					if (food.loc == snake.GetNextHeadLocation(deltaLoc))
					{
						food.isEaten = true;
						NetPoints += food.points;
						nFoodGoal += 1;
						snake.Grow();
					}

					snake.MoveBy(deltaLoc);
				}
			}
		}
		if (food.isEaten == true) {
			food.isEaten = false;

			std::uniform_int_distribution<int> Distx(0, board.getGridWidth() - 1);
			std::uniform_int_distribution<int> Disty(0, board.getGridHeight() - 1);

			Location newloc = Location(Distx(rng), Disty(rng));
			while (snake.IsSegmentInTile(newloc)) {
				newloc = Location(Distx(rng), Disty(rng));
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
		break;
	case GAMEOVER:
		if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			gameOver = false;
			gameState = TITLE;
		}
		break;
	default:
		break;
	}
}

//Function to render the frame
void Game::Draw()
{
	switch (gameState)
	{
	case TITLE:
		//Title Screen
		gfx.DrawRect((int)x - 1, (int)y - 1, 800 + 2, 800 + 2, false, Color(0, 0, 200));
		//board.drawTitle(board);
		gfx.DrawSprite(100, 100, titleScreen);
		break;
	case GAME:
		gfx.DrawRect((int)x - 1, (int)y - 1, 800 + 1, 800 + 1, false, Color(255, 255, 255));
		snake.Draw();
		food.Draw(board);
		break;
	case GAMEOVER:
		//Game Over Screen
		gfx.DrawRect((int)x - 1, (int)y - 1, 800 + 2, 800 + 2, true, Color(255, 0, 0));
		gfx.DrawSprite(100, 100, gameOverScreen);
		std::cout << NetPoints << " ";
		break;
	default:
		break;
	}
}

void Game::Reset()
{
	snake = Snake(startLoc);
	canChangeDirection = true;
	gameOver = false;
	NetPoints = 0;
	nFoodGoal = 0;
	snakeSpeed = 5;
	accurateSnakeSpeed = 0;
	deltaLoc = Location(1, 0);
}
