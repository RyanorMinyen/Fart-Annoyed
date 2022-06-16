#include "Paddle.h"

Paddle::Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in):
	pos(pos_in),halfWidth(halfWidth_in),halfHeight(halfHeight_in)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	RectF rect = GetRect();

	gfx.DrawRect(rect, wingColor);
	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect(rect, color);


}

bool Paddle::DoBallCollison(Ball& ball) const
{
	const RectF rect = GetRect();

	if (ball.GetVelocity().y > 0.0f && rect.IsOverLappingWith(ball.GetRect())) {

		ball.ReboundY();
		return true;
	}

	return false;
}

void Paddle::DoWallCollison(const RectF& walls)
{
    const RectF rect = GetRect();

    if (rect.left < walls.left) {
        pos.x += walls.left - rect.left;
     
    }
    else if (rect.right > walls.right) {
        pos.x -= rect.right - walls.right;
 
    }

}

void Paddle::Update(float dt, Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {

		pos.x -= dt * speed;
	}

	if (kbd.KeyIsPressed(VK_RIGHT)) {
		pos.x += dt * speed;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos,halfWidth,halfHeight);
}
