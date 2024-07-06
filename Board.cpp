#include "Board.h"
#include <assert.h>

Board::Board()
{

}

void Board::DrawCell(Location loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	gfx.DrawRect(boardLocOffset.x + (loc.x * dimention), boardLocOffset.y + (loc.y * dimention), dimention, dimention, true, c);
}

bool Board::IsInBoard(const Location loc) const
{
	return (loc.x >= 0 && loc.x < width) && (loc.y >= 0 && loc.y < height);
}

void Board::drawTitle(Board board)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 20; j++) {
			if (snakeGameTitle[i][j] == 1) {
				board.DrawCell(Location(j+10, i+10), Color(255, 255, 255));
			}
		}
	}
}

