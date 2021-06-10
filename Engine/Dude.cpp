#include "Dude.h"

void Dude::ClampToScreen()
{
	const int right = x + width;
	if (x < 0)
	{
		return 0;
	}
	else if (right >= gfx.ScreenWidth)
	{
		return (gfx.ScreenWidth - 1) - width;
	}
	else
	{
		return x;
	}
	const int bottom = y + height;
	if (y < 0)
	{
		return 0;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		return (gfx.ScreenHeight - 1) - height;
	}
	else
	{
		return y;
	}
}
