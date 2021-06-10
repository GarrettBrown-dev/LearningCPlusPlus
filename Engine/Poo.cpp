#include "Poo.h"

void Poo::Update()
{
	x += vx;
	y += vy;

	const int right = x + width;
	if (x < 0)
	{
		x = 0;
	}
	else if (right >= gfx.ScreenWidth)
	{
		x = (gfx.ScreenWidth - 1) - width;
	}
	else
	{
		return x;
	}
	const int bottom = y + height;
	if (y < 0)
	{
		y = 0;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		y = (gfx.ScreenHeight - 1) - height;
	}
	else
	{
		return y;
	}
}