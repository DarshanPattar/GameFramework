#pragma once

#include "Board.h"

class Snake {
private:
	class Segment {
	public:
		Segment();
		void InitHead(Location loc);
		void InitBody();
		void MoveBy(Location deltaLoc);
		void Follow(Segment next);
		void Draw(Board board);
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location loc);
	void MoveBy(Location deltaLoc);
	void Grow();
	void Draw();
private:
	static constexpr int nSegmentsMax = 1600;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	Board board;
};