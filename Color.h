#pragma once
#include<GLFW/glfw3.h>

class Color {
public:
	Color() {}
	Color(int r, int g, int b);
	~Color();

	float r;
	float g;
	float b;
};