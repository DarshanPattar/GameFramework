#pragma once
#include "Graphics.h"
#include "Location.h"


class Board {
public:
	Board();
	void DrawCell(Location loc, Color c);

	int getGridHeight() const{
		return height;
	}
	int getGridWidth() const{
		return width;
	}
	Location getGridLocation() const{
		return boardLocOffset;
	}
	bool IsInBoard(const Location loc) const;

	void drawTitle(Board board);
private:
	Location boardLocOffset = Location(100, 100);
	static constexpr int dimention = 20;
	static constexpr int width = 40;
	static constexpr int height = 40;
	Graphics gfx;

	int snakeGameTitle[5][20] = {
		{1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1},
		{1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1},
		{0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1}
	};


};