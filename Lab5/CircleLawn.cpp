#include "CircleLawn.h"

CircleLawn::CircleLawn(unsigned int radius)
	: Lawn(radius* radius * 3.14 + 0.5)
	, mArea(radius* radius * 3.14 + 0.5)
{
}

CircleLawn::~CircleLawn()
{
}

unsigned int CircleLawn::GetArea() const
{
	return mArea;
}
