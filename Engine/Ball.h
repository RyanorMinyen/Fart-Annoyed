#pragma once
#include "SpriteCodex.h"
#include "Vec2.h"

class Ball {
public:

	Ball(const Vec2& pos, const Vec2& vel);
	bool DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	void DrawBall(Graphics& gfx)const;
private:
	
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};
