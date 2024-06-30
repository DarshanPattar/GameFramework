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
	Color() {}
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
	void DrawRect(int xpos, int ypos, int width, int height, bool fill, Color c);
	void DrawLine(int x1, int y1, int x2, int y2, Color c);
private:
	static Coordinate ObjToScreen(int x, int y);
};
