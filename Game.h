#pragma once
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "Surface.h"
#include <random>


enum GameState {
	TITLE, GAME, GAMEOVER
};


class Game {
private:
	Graphics gfx;
	float x = 100, y = 100;
public:
	Game();
	void Start(GLFWwindow* window);
	void Update(double dt);
	void Draw();

	void Reset();

	
	Board board;
	GLFWwindow* window;

	Location deltaLoc = Location(1, 0);
	const Location startLoc = Location(15, 15);
	Snake snake = Snake(startLoc);

	int snakeSpeed = 5;
	float accurateSnakeSpeed = 0;

	Location UP = Location(0, -1);
	Location DOWN = Location(0, 1);
	Location LEFT = Location(-1, 0);
	Location RIGHT = Location(1, 0);

	bool gameOver = false;
	bool canChangeDirection = true;

	int NetPoints = 0;

	Food food;
	int nFoodGoal = 0;
	const int boostPointMark = 5;

	std::mt19937 rng;

	GameState gameState = TITLE;

	Surface titleScreen = Surface("TitleScreen.bmp");
	Surface gameOverScreen = Surface("GameOverScreen.bmp");
};