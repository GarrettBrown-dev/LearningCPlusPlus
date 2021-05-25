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
	ComposeFrame(); //Render the most up-to-date version of the game in a frame.
	gfx.EndFrame(); //Present the frame to the user.
}

void Game::UpdateModel()
{
}

//Variables come into existence when declared and end at the end of the function they're declared in. (As with other languages.) This is the scope. Local variables WILL override the Header variables.
void Game::ComposeFrame()
{


	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) //If a variable is redeclared within a function, the one in the function takes precident.
	{
		x = x + 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x = x - 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y = y - 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y = y + 3;
	}

	int gb = 255;

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		gb = 0; //Green and Blue Values.
	}

	if (wnd.kbd.KeyIsPressed(VK_SHIFT)) //Changes Shape of Crosshair
	{
		gfx.PutPixel(-10 + x, y,255, gb, gb); //(X,Y,R,G,B)
		gfx.PutPixel(-9 + x, y, 255, gb, gb);
		gfx.PutPixel(-8 + x, y, 255, gb, gb);
		gfx.PutPixel(8 + x, y,  255, gb, gb);
		gfx.PutPixel(9 + x, y,  255, gb, gb);
		gfx.PutPixel(10 + x, y, 255, gb, gb);
		gfx.PutPixel(x,-10 + y, 255, gb, gb);
		gfx.PutPixel(x, -9 + y, 255, gb, gb);
		gfx.PutPixel(x, -8 + y, 255, gb, gb);
		gfx.PutPixel(x, 8 + y,  255, gb, gb);
		gfx.PutPixel(x, 9 + y,  255, gb, gb);
		gfx.PutPixel(x, 10 + y, 255, gb, gb);
	}
	else
	{
		gfx.PutPixel(-5 + x, y, 255, gb, gb); //(X,Y,R,G,B)
		gfx.PutPixel(-4 + x, y, 255, gb, gb);
		gfx.PutPixel(-3 + x, y, 255, gb, gb);
		gfx.PutPixel(3 + x, y, 255, gb, gb);
		gfx.PutPixel(4 + x, y, 255, gb, gb);
		gfx.PutPixel(5 + x, y, 255, gb, gb);
		gfx.PutPixel(x, -5 + y, 255, gb, gb);
		gfx.PutPixel(x, -4 + y, 255, gb, gb);
		gfx.PutPixel(x, -3 + y, 255, gb, gb);
		gfx.PutPixel(x, 3 + y, 255, gb, gb);
		gfx.PutPixel(x, 4 + y, 255, gb, gb);
		gfx.PutPixel(x, 5 + y, 255, gb, gb);
	}
	
}
