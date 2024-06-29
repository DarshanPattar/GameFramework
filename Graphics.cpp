#include "Graphics.h"

void Graphics::PutPixel(int x, int y, int r, int g, int b)
{
	Coordinate pos = ObjToScreen(x, y);
	Color c(r, g, b);
	glColor3f(c.r, c.g, c.b);
	glBegin(GL_POINTS);
	glVertex2f(pos.x, pos.y);
	glEnd();
}

void Graphics::PutPixel(int x, int y, Color c)
{
	Coordinate pos = ObjToScreen(x, y);
	glColor3f(c.r, c.g, c.b);
	glBegin(GL_POINTS);
	glVertex2f(pos.x, pos.y);
	glEnd();
}

Coordinate Graphics::ObjToScreen(int x, int y)
{
	float NormalX = (float)((float)x - 0) / (SCREENWIDTH - 0) * (1 - (-1)) + (-1);
	float NormalY = (float)((float)y - 0) / (SCREENHEIGHT - 0) * (1 - (-1)) + (-1);
	Coordinate point;
	point.x = NormalX;
	point.y = NormalY;
	return point;
}

Color::Color(int ir, int ig, int ib)
{
	r = (GLfloat)ir / 255;
	g = (GLfloat)ig / 255;
	b = (GLfloat)ib / 255;
}

Color::~Color()
{
}
