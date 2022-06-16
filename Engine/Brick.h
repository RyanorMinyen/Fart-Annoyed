#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"


class Brick {

public:
	Brick() = default;
	Brick(const RectF& rect_in, Color color_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	bool DoBallCollision(Ball& ball);
	
private:
	
	static constexpr float padding = 1.0f;
	bool destroyed = false;
	RectF rect;
	Color color;
	

};