#include "RectF.h"
#include "Graphics.h"

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

void RectF::DrawBoarder(class Graphics& gfx)
{
   // DrawRect(int(rect.left), int(rect.top), int(rect.right), int(rect.bottom), c);
    // top
    gfx.DrawRect(int(170.0f - boarderThickness), int(0.0f), int(630.0f),int(boarderThickness), Colors::Blue);
    // bottom
    gfx.DrawRect(int(170.0f - boarderThickness), int(595.0f), int(630.0f), int(600.0f), Colors::Blue);
    //left
    gfx.DrawRect(int(170.0f - boarderThickness), int(0.0f), int(170.0f), int(600.0f), Colors::Blue);
    //right
    gfx.DrawRect(int(630.0f), int(0.0f), int(630.0f+boarderThickness), int(600.0f), Colors::Blue);
  
}

void RectF::DrawBackdrop(Graphics& gfx)
{
    gfx.DrawRect(int(175.0f - boarderThickness), int(0.0f),int( 630.0f), int(600.0f), Colors::Gray);
}
