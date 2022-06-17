#include "Brick.h"
#include <assert.h>
#include <cmath>

Brick::Brick(const RectF& rect_in, Color color_in):
	rect(rect_in),
	color(color_in)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed) {
		gfx.DrawRect(rect.GetExpanded(padding), color);
	}
	
}

bool Brick::CheckBallCollision(const Ball& ball) const
{
	
	if (!destroyed && rect.IsOverLappingWith(ball.GetRect())) {
		
		return true;
	}

	return false;
}

void Brick::ExecuteBallCollision(Ball& ball)
{

	assert(CheckBallCollision(ball));
	RectF ballRect = ball.GetRect();

	if (std::signbit(ball.GetVelocity().x) == std::signbit((ball.GetRect().GetCenter().x) - (rect.GetCenter().x))) {
		ball.ReboundY();
	}else if (ballRect.GetCenter().x > rect.left && ballRect.GetCenter().x < rect.right) {

		ball.ReboundY();
	}
	else {
		ball.ReboundX();
	}

	destroyed = true;

}




Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
