#pragma once

#include "Color.h"
#include<string>

class Surface {

public:
	Surface(int width, int height);
	Surface(const Surface&);
	Surface(const std::string& filename);

	~Surface();
	Surface& operator=(const Surface&);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
private:
	Color *pPixel = nullptr;
	int width;
	int height;
};