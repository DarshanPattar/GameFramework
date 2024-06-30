#pragma once


class Location {
public:
	Location() {}
	Location(int xi, int yi) {
		x = xi;
		y = yi;
	}
	void Add(Location loc) {
		x += loc.x;
		y += loc.y;
	}
public:
	int x;
	int y;
};