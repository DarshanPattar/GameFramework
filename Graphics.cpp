#include "Graphics.h"
#include<math.h>

/*
PutPixel function places a pixel on the screen with Color in RGB format or Using a Color Object
PutPixel(int x, int y, int r, int g, int b);
		-Coordinates-----Color in RGB ----

PutPixel(int x, int y, Color c);
		-Coordinates-Color OBJ-
*/
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


//Fill parameter is boolean type : fill = painted, !fill = just borders
void Graphics::DrawRect(int xpos, int ypos, int width, int height, bool fill, Color c)
{
	for (int i = ypos; i < ypos + height; i++) {
		for (int j = xpos; j < xpos + width; j++) {
			if (fill) {
				PutPixel(j, i, c);
			}else{
				if (j == xpos || j == xpos + width - 1 || i == ypos || i == ypos + height - 1) {
					PutPixel(j, i, c);
				}
			}
		}
	}
}

//Bresenham's Line drawing function
void Graphics::DrawLine(int x1, int y1, int x2, int y2, Color c)
{
	int x, y, xi = 1, yi = 1;
	float p;
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	if (x2 < x1)
		xi = -1;
	if (y2 < y1)
		yi = -1;
	x = x1;
	y = y1;
	if (dx > dy) {
		PutPixel(x, y, c);
		p = 2 * dy - dx;
		for (int i = 0; i < dx; i++)
		{
			if (p >= 0) {
				y += yi;
				p += 2 * (dy - dx);
			}
			else {
				p += 2 * dy;
			}
			x += xi;
			PutPixel(x, y, c);
		}
	}
	else {
		PutPixel(x, y, c);
		p = 2 * dx - dy;
		for (int i = 0; i < dy; i++)
		{
			if (p >= 0) {
				x += xi;
				p += 2 * (dx - dy);
			}
			else {
				p += 2 * dx;
			}
			y += yi;
			PutPixel(x, y, c);
		}
	}
}

void Graphics::DrawSprite(int x, int y, const Surface& surface)
{
	const int width = surface.GetWidth();
	const int height = surface.GetHeight();
	for (int sy = 0; sy < height; sy++) {
		for (int sx = 0; sx < width; sx++) {
			PutPixel(x + sx, y + sy, surface.GetPixel(sx, sy));
		}
	}
}

// maps [0, length] coordinates to [-1, 1]
// like if (0, 0) coordinate is basically (-1, -1) on screen
Coordinate Graphics::ObjToScreen(int x, int y)
{
	float NormalX = (float)((float)x - 0) / (SCREENWIDTH - 0) * (1 - (-1)) + (-1);
	float NormalY = -(float)((float)y - 0) / (SCREENHEIGHT - 0) * (1 - (-1)) + (1);
	Coordinate point;
	point.x = NormalX;
	point.y = NormalY;
	return point;
}

