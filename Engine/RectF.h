#pragma once
#include "Vec2.h"


class RectF {

public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& TopLeft, const Vec2& BottomRight);
	RectF(const Vec2& TopLeft, float Width, float Height);
	bool IsOverLappingWith(const RectF& other) const;


public:
	float left;
	float right;
	float top;
	float bottom;
};