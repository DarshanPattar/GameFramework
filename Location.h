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
	bool operator==(Location l1) {
		return (l1.x == x && l1.y == y);
	}
public:
	int x;
	int y;
};