#pragma once
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"

class Game {
private:
	Graphics gfx;
	float x = 100, y = 100;
public:
	Game();
	void Start(GLFWwindow* window);
	void Update(double dt);
	void Draw();

	Snake snake = Snake(Location(15, 15));
	Board board;
	GLFWwindow* window;
	Location deltaLoc = Location(1, 0);

	int snakeSpeed = 3;
	float accurateSnakeSpeed = 0;

	Location UP = Location(0, -1);
	Location DOWN = Location(0, 1);
	Location LEFT = Location(-1, 0);
	Location RIGHT = Location(1, 0);
};