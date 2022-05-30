#include "CircleLawn.h"

CircleLawn::CircleLawn(unsigned int radius)
	: Lawn(static_cast<unsigned int>(radius * radius * 3.14 + 0.5))
	, mArea(static_cast<unsigned int>(radius * radius * 3.14 + 0.5))
{
}

CircleLawn::~CircleLawn()
{
}

unsigned int CircleLawn::GetArea() const
{
	return mArea;
}
