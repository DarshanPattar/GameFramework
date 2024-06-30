#pragma once
#include "Graphics.h"
#include "Board.h"
#include <random>

class Game {
private:
	Graphics gfx;
	float x = 100, y = 100;
public:
	Game();
	void Start();
	void Update(double dt);
	void Draw();

	Board board;

};