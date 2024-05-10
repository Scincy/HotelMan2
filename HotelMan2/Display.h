#pragma once
#define ArrowLEFT 75
#define ArrowRIGHT 77
#define ArrowUP 72
#define ArrowDOWN 80
typedef enum
{
	Black = 0,
	DarkBlue = 1,
	DarkGreen = 2,
	DarkSkyBlue = 3,
	DarkRed = 4,
	DarkPurple = 5,
	DarkYellow = 6,
	Gray = 7,
	DarkGray = 8,
	Blue = 9,
	Green = 10,
	SkyBlue = 11,
	Red = 12,
	Purple = 13,
	Yellow = 14,
	White = 15
}TextColor;

void openMenu(int menuID);