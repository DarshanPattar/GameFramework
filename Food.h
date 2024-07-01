#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Board.h"


class Food {
public:
	Location loc;
	Color c;
	int points = 1;
	bool isEaten = false;
	void Draw(Board& board) {
		board.DrawCell(loc, c);
	}
};