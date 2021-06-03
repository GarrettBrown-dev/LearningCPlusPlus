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
}

//Variables come into existence when declared and end at the end of the function they're declared in. (As with other languages.) This is the scope. Local variables WILL override the Header variables.
void Game::ComposeFrame()
{
	const int r_fixed = 0;
	const int g_fixed = 255;
	const int b_fixed = 0;

	gfx.PutPixel(-5 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + x_fixed, -4 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + x_fixed, -3 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-4 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-3 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + x_fixed, 4 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + x_fixed, 3 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-4 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-3 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + x_fixed, -4 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + x_fixed, -3 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(4 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(3 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + x_fixed, 4 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + x_fixed, 3 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(4 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(3 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);

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
//{
//	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) //If a variable is redeclared within a function, the one in the function takes precident.
//	{
//		if (inhibitRight)
//		{
//		}
//		else
//		{
//			x_mobile = x_mobile + 1;
//			inhibitRight = true;
//		}
//	}
//	else
//	{
//		inhibitRight = false;
//	}
//
//	if (wnd.kbd.KeyIsPressed(VK_LEFT))
//	{
//		if (inhibitLeft)
//		{
//		}
//		else
//		{
//			x_mobile = x_mobile - 1;
//			inhibitLeft = true;
//		}
//	}
//	else
//	{
//		inhibitLeft = false;
//	}
//
//
//	if (wnd.kbd.KeyIsPressed(VK_UP))
//	{
//		if (inhibitUp)
//		{
//		}
//		else
//		{
//			y_mobile = y_mobile - 1;
//			inhibitUp = true;
//		}
//	}
//	else
//	{
//		inhibitUp = false;
//	}
//
//	if (wnd.kbd.KeyIsPressed(VK_DOWN))
//	{
//		if (inhibitDown)
//		{
//		}
//		else
//		{
//			y_mobile = y_mobile + 1;
//			inhibitDown = true;
//		}
//	}
//	else
//	{
//		inhibitDown = false;
//	}
//
//	x = x + vx;
//	y = y + vy;
//
//	if (x + 5 >= gfx.ScreenWidth)
//	{
//		x = gfx.ScreenWidth - 6;
//		vx = 0;
//	}
//
//	if (x - 5 < 0)
//	{
//		x = 5;
//		vx = 0;
//	}
//
//	if (y + 5 >= gfx.ScreenHeight)
//	{
//		y = gfx.ScreenHeight - 6;
//		vy = 0;
//	}
//
//	if (y - 5 < 0)
//	{
//		y = 5;
//		vy = 0;
//	}
//
//	shapeIsChanged = false;
//	if (x > 200 || x < 300)
//	{
//		shapeIsChanged = true;
//	}
//
//	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
//	{
//		gb = 0; //Green and Blue Values.
//	}
//
//	//shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
//
//}

//if (shapeIsChanged) //Changes Shape of Crosshair
//{
//	gfx.PutPixel(-10 + x, y,255, gb, gb); //(X,Y,R,G,B)
//	gfx.PutPixel(-9 + x, y, 255, gb, gb);
//	gfx.PutPixel(-8 + x, y, 255, gb, gb);
//	gfx.PutPixel(8 + x, y,  255, gb, gb);
//	gfx.PutPixel(9 + x, y,  255, gb, gb);
//	gfx.PutPixel(10 + x, y, 255, gb, gb);
//	gfx.PutPixel(x,-10 + y, 255, gb, gb);
//	gfx.PutPixel(x, -9 + y, 255, gb, gb);
//	gfx.PutPixel(x, -8 + y, 255, gb, gb);
//	gfx.PutPixel(x, 8 + y,  255, gb, gb);
//	gfx.PutPixel(x, 9 + y,  255, gb, gb);
//	gfx.PutPixel(x, 10 + y, 255, gb, gb);
//}
//else
//{
//	gfx.PutPixel(-5 + x, y, 255, gb, gb); //(X,Y,R,G,B)
//	gfx.PutPixel(-4 + x, y, 255, gb, gb);
//	gfx.PutPixel(-3 + x, y, 255, gb, gb);
//	gfx.PutPixel(3 + x, y, 255, gb, gb);
//	gfx.PutPixel(4 + x, y, 255, gb, gb);
//	gfx.PutPixel(5 + x, y, 255, gb, gb);
//	gfx.PutPixel(x, -5 + y, 255, gb, gb);
//	gfx.PutPixel(x, -4 + y, 255, gb, gb);
//	gfx.PutPixel(x, -3 + y, 255, gb, gb);
//	gfx.PutPixel(x, 3 + y, 255, gb, gb);
//	gfx.PutPixel(x, 4 + y, 255, gb, gb);
//	gfx.PutPixel(x, 5 + y, 255, gb, gb);
//}

//gfx.PutPixel(-10 + x, y, 255, gb, gb); //(X,Y,R,G,B)
//gfx.PutPixel(-9 + x, y, 255, gb, gb);
//gfx.PutPixel(-8 + x, y, 255, gb, gb);
//gfx.PutPixel(8 + x, y, 255, gb, gb);
//gfx.PutPixel(9 + x, y, 255, gb, gb);
//gfx.PutPixel(10 + x, y, 255, gb, gb);
//gfx.PutPixel(x, -10 + y, 255, gb, gb);
//gfx.PutPixel(x, -9 + y, 255, gb, gb);
//gfx.PutPixel(x, -8 + y, 255, gb, gb);
//gfx.PutPixel(x, 8 + y, 255, gb, gb);
//gfx.PutPixel(x, 9 + y, 255, gb, gb);
//gfx.PutPixel(x, 10 + y, 255, gb, gb);
