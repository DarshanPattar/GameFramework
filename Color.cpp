#include "Color.h"

//Constructor that takes 8 bit color value and stores normalized values [0, 1]
Color::Color(int ir, int ig, int ib)
{
	if (ir > 255)ir = 255;
	if (ir < 0)ir = 0;
	if (ig > 255)ig = 255;
	if (ig < 0)ig = 0;
	if (ib > 255)ib = 255;
	if (ib < 0)ib = 0;

	r = (GLfloat)ir / 255;
	g = (GLfloat)ig / 255;
	b = (GLfloat)ib / 255;
}

Color::~Color()
{
}

