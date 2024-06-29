#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Macros.h"


class Coordinate {
public:
	float x;
	float y;
};

class Color {
public:

	Color(int r, int g, int b);
	~Color();

	float r;
	float g;
	float b;
};

class Graphics {
public:
	void PutPixel(int x, int y, int r, int g, int b);
	void PutPixel(int x, int y, Color c);

private:
	static Coordinate ObjToScreen(int x, int y);
};
