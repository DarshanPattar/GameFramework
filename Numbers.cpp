#include "Numbers.h"

void Numbers::DrawNumber(int n, int digits)
{
	int number = n;
	int digitCount = 0;
	int rem = 0;

	while (number != 0) {
		rem = (int)number % 10;
		number = (int)number % 10;
		digitCount++;

		switch (rem) {
		case 0:
			draw1Number(digits - digitCount, Num0);
			break;
		case 1:
			draw1Number(digits - digitCount, Num1);
			break;
		case 2:
			draw1Number(digits - digitCount, Num2);
			break;
		case 3:
			draw1Number(digits - digitCount, Num3);
			break;
		case 4:
			draw1Number(digits - digitCount, Num4);
			break;
		case 5:
			draw1Number(digits - digitCount, Num5);
			break;
		case 6:
			draw1Number(digits - digitCount, Num6);
			break;
		case 7:
			draw1Number(digits - digitCount, Num7);
			break;
		case 8:
			draw1Number(digits - digitCount, Num8);
			break;
		case 9:
			draw1Number(digits - digitCount, Num9);
			break;
		default:
			break;
		}
	}
}

void Numbers::draw1Number(int digit, const int Num[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (Num[j][i] == 1) {
				DrawPoint(i + 4 * digit, j);
			}
		}
	}
}

void Numbers::DrawPoint(int x, int y)
{
	gfx.DrawRect(x*pointSize, y*pointSize, pointSize, pointSize, true, Color(255, 255, 255));
}
