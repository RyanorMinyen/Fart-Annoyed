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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(300.0f,300.0f),Vec2(300.0f,300.0f)),
	walls(RectF(Vec2(0.0f,0.0f),Vec2(Graphics::ScreenWidth, Graphics::ScreenHeight))),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav"),
	pad(Vec2(400.0f,500.0f), 50.0f, 15.0f)
{
	const Vec2 topLeft = { 40.0f, 40.0f };

	const Color colors[5] = { Colors::Red, Colors::Blue, Colors::Magenta, Colors::Yellow, Colors::Green };

	int i = 0;
	for (int y = 0; y < nBricksDown; y++) {
		
		Color rowColor = colors[y];
		for (int x = 0; x < nBricksAcross; x++) {
			
			bricks[i] = Brick(RectF(Vec2(topLeft.x + x * brickWidth, topLeft.y + y * brickHeight), brickWidth, brickHeight),rowColor);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f) {
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	
	ball.Update(dt);
	pad.Update(dt, wnd.kbd);
	pad.DoWallCollison(walls);
	
	bool collisionHappened = false;
	float currColDistSq;
	int currColIndex;

	for (int i = 0; i < nBricks; i++) {
		
		if (bricks[i].CheckBallCollision(ball)) {

			const float newColDistSq = (ball.GetRect().GetCenter() - bricks[i].GetCenter()).GetLengthSq();

			if (collisionHappened) {
				
				if (newColDistSq < currColDistSq) {
					currColDistSq = newColDistSq;
					currColIndex = i;
				}
				
			}
			else {
				collisionHappened = true;
				currColDistSq = newColDistSq;
				currColIndex = i;
			}
		}	
	}

	if (collisionHappened) {
		
		pad.resetCooldown();
		bricks[currColIndex].ExecuteBallCollision(ball);
		soundBrick.Play();
	}
	
	
	if (pad.DoBallCollison(ball)) {
		
		soundPad.Play();
	}
	if (ball.DoWallCollision(walls)) {
		pad.resetCooldown();
		soundPad.Play();
		
	}
	


}

void Game::ComposeFrame()
{
	for (const auto& brick : bricks) {
		brick.Draw(gfx);
	}
	ball.DrawBall(gfx);
	pad.Draw(gfx);
}
