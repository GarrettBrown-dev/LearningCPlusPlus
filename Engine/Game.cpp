/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

//CPP Files are the corresponding code files for Headers and contain the actual behaviors for the class and what will happen when a function is activated.
Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go() // the whole function is a frame of the game.
{
	gfx.BeginFrame();	//Create the frame.
	UpdateModel(); //Update the frame.
	ComposeFrame(); //Render the most up-to-date version of the game in a frame. If you wanted an exclusively server based form of the game, you could simply comment out the compose frame function.
	gfx.EndFrame(); //Present the frame to the user.
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x_mobile = x_mobile + 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x_mobile = x_mobile - 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y_mobile = y_mobile + 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y_mobile = y_mobile - 1;
	}

	const int left_mobile = x_mobile - 5;
	const int right_mobile = x_mobile + 5;
	const int top_mobile = y_mobile - 5;
	const int bottom_mobile = y_mobile + 5;

	const int left = x_fixed - 5;
	const int right = x_fixed + 5;
	const int top = y_fixed - 5;
	const int bottom = y_fixed + 5;

	if (left_mobile < right &&
		right_mobile > left &&
		top_mobile < bottom &&
		bottom_mobile > top)
	{
		colliding = true;
	}
	else
	{
		colliding = false;
	}
}

//Variables come into existence when declared and end at the end of the function they're declared in. (As with other languages.) This is the scope. Local variables WILL override the Header variables.
void Game::ComposeFrame()
{
	DrawBox(x_fixed, y_fixed, 255, 255, 255);

	int r_mobile, g_mobile, b_mobile;

	if (colliding)
	{
		r_mobile = 255;
		g_mobile = 0;
		b_mobile = 0;
	}
	else
	{
		r_mobile = 255;
		g_mobile = 255;
		b_mobile = 255;
	}

	gfx.PutPixel(-5 + x_mobile, -5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(-5 + x_mobile, -4 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(-5 + x_mobile, -3 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(-4 + x_mobile, -5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(-3 + x_mobile, -5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(-5 + x_mobile, 5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(-5 + x_mobile, 4 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(-5 + x_mobile, 3 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(-4 + x_mobile, 5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(-3 + x_mobile, 5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(5 + x_mobile, -5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(5 + x_mobile, -4 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(5 + x_mobile, -3 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(4 + x_mobile, -5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(3 + x_mobile, -5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(5 + x_mobile, 5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(5 + x_mobile, 4 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(5 + x_mobile, 3 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(4 + x_mobile, 5 + y_mobile, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(3 + x_mobile, 5 + y_mobile, r_mobile, g_mobile, b_mobile);

}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(-5 + x, -4 + y, r, g, b);
	gfx.PutPixel(-5 + x, -3 + y, r, g, b);
	gfx.PutPixel(-4 + x, -5 + y, r, g, b);
	gfx.PutPixel(-3 + x, -5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 4 + y, r, g, b);
	gfx.PutPixel(-5 + x, 3 + y, r, g, b);
	gfx.PutPixel(-4 + x, 5 + y, r, g, b);
	gfx.PutPixel(-3 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, -4 + y, r, g, b);
	gfx.PutPixel(5 + x, -3 + y, r, g, b);
	gfx.PutPixel(4 + x, -5 + y, r, g, b);
	gfx.PutPixel(3 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, 4 + y, r, g, b);
	gfx.PutPixel(5 + x, 3 + y, r, g, b);
	gfx.PutPixel(4 + x, 5 + y, r, g, b);
	gfx.PutPixel(3 + x, 5 + y, r, g, b);
}
