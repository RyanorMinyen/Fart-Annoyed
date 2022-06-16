#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in):
    left(left_in),
    right(right_in),
    top(top_in),
    bottom(bottom_in)
{
    
}

RectF::RectF(const Vec2& TopLeft, const Vec2& BottomRight):
    RectF(TopLeft.x, BottomRight.x, TopLeft.y, BottomRight.y)
{
    
}

RectF::RectF(const Vec2& TopLeft, float Width, float Height) :
    RectF(TopLeft, Vec2(TopLeft.x + Width, TopLeft.y + Height))
{
}

bool RectF::IsOverLappingWith(const RectF& other) const
{
    return left < other.right && right > other.left &&
        top < other.bottom && bottom > other.top;
}
