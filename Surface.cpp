#include "Surface.h"
#include "Windows.h"
#include "fstream"
#include <assert.h>

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixel(new Color[width*height])
{
}

Surface::Surface(const Surface& sur)
	:
	Surface(sur.width, sur.height)
{
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++) {
		pPixel[i] = sur.pPixel[i];
	}
}

Surface::Surface(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);

	BITMAPFILEHEADER bmFileHeader;
	file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	assert(bmInfoHeader.biBitCount == 24);
	assert(bmInfoHeader.biCompression == BI_RGB);

	width = bmInfoHeader.biWidth;
	height = bmInfoHeader.biHeight;

	pPixel = new Color[width * height];

	file.seekg(bmFileHeader.bfOffBits);

	const int padding = (4 - (width * 3) % 4) % 4;
	for (int y = height - 1; y >= 0; y--) {
		for (int x = 0; x < width; x++) {
			PutPixel(x, y, Color(file.get(), file.get(), file.get()));
		}
		file.seekg(padding, std::ios::cur);
	}

}

Surface::~Surface()
{
	delete [] pPixel;
	pPixel = nullptr;
}

Surface& Surface::operator=(const Surface& rhs)
{
	width = rhs.width;
	height = rhs.height;

	delete[] pPixel;

	pPixel = new Color[width * height];
	const int npix = width * height;
	for (int i = 0; i < npix; i++) {
		pPixel[i] = rhs.pPixel[i];
	}
	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	pPixel[y * width + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	return pPixel[y * width + x];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}
