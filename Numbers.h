#pragma once
#include "Graphics.h"

class Numbers {
private:
	const int Num8[5][4] = {
		{1, 1, 1, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 0}
	};
	const int Num0[5][4] = {
		{1, 1, 1, 0},
		{1, 0, 1, 0},
		{1, 0, 1, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 0}
	};
	const int Num1[5][4] = {
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0}
	};
	const int Num2[5][4] = {
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{1, 1, 1, 0},
		{1, 0, 0, 0},
		{1, 1, 1, 0}
	};
	const int Num3[5][4] = {
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{1, 1, 1, 0}
	};
	const int Num4[5][4] = {
		{1, 0, 1, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0}
	};
	const int Num5[5][4] = {
		{1, 1, 1, 0},
		{1, 0, 0, 0},
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{1, 1, 1, 0}
	};
	const int Num6[5][4] = {
		{1, 1, 1, 0},
		{1, 0, 0, 0},
		{1, 1, 1, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 0}
	};
	const int Num7[5][4] = {
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0}
	};
	const int Num9[5][4] = {
		{1, 1, 1, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{1, 1, 1, 0}
	};

	int pointSize = 5;
	int height = 5;
	Graphics gfx;

public:
	void DrawNumber(int n, int digits);
	void draw1Number(int digit, const int num[][4]);
	void DrawPoint(int x, int y);

};
