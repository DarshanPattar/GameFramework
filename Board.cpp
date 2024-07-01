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
