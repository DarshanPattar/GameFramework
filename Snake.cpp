#include "Snake.h"

Snake::Snake(const Location loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(Location deltaLoc)
{
	for (int i = nSegments - 1; i > 0; i--) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(deltaLoc);
}

Location Snake::GetNextHeadLocation(const Location deltaLoc) const
{
	Location l(segments[0].GetLocation());
	l.Add(deltaLoc);
	return l;
}

bool Snake::IsSegmentInTile(const Location& target) const
{
	for (int i = 0; i < nSegments - 1; i++) {
		if (target == segments[i].GetLocation()) {
			return true;
		}
	}
	return false;
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax) {
		segments[nSegments].InitBody();
		nSegments++;
	}
}

void Snake::Draw()
{
	for (int i = 0; i < nSegments; i++) {
		segments[i].Draw(board);
	}
}

Snake::Segment::Segment()
{
}

void Snake::Segment::InitHead(Location loc_in)
{
	loc = loc_in;
	c = Color(255, 255, 0);
}

void Snake::Segment::InitBody()
{
	c = Color(150, 255, 0);
}

void Snake::Segment::MoveBy(Location deltaLoc)
{
	loc.Add(deltaLoc);
}

void Snake::Segment::Follow(Segment next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board board)
{
	board.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
