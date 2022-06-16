#pragma once
#include "RectF.h"
#include "Graphics.h"


class Brick {

public:
	Brick() = default;
	Brick(const RectF& rect_in, Color color_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt);

private:
	
	bool destroyed = false;
	RectF rect;
	Color color;
	

};