#pragma once

#include "Ball.h"
#include "Graphics.h"
#include "RectF.h"
#include "Keyboard.h"

class Paddle {

public:
	Paddle(const Vec2& pos, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx) const;
	bool DoBallCollison(Ball& ball);
	void DoWallCollison(const RectF& walls);
	void Update(float dt, Keyboard& kbd);
	RectF GetRect() const;
	void resetCooldown();


private:

	Color color = Colors::White;
	bool isCooldown = false;
	static constexpr float wingWidth = 18.0f;
	Color wingColor = Colors::Red;
	Vec2 pos;
	float speed = 300.0f;
	float halfWidth;
	float halfHeight;
};
