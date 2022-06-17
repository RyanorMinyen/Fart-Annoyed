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

RectF RectF::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
    Vec2 x = { halfWidth, halfHeight };
    return RectF(Vec2(center - x), Vec2(center + x));
}

RectF RectF::GetExpanded(float offset) const
{
    return RectF(left+offset, right-offset, top+offset, bottom-offset);
}

Vec2 RectF::GetCenter() const
{
    return Vec2((left + right) / 2.0f, (top + bottom)/ 2.0f);
}
