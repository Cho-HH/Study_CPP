#include "EquilateralTriangleLawn.h"

EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int side)
	: Lawn(sqrt(3) / 4 * side * side + 0.5)
	, mArea(sqrt(3) / 4 * side * side + 0.5)
	, mSide(side)
{
}

EquilateralTriangleLawn::~EquilateralTriangleLawn()
{
}

unsigned int EquilateralTriangleLawn::GetArea() const
{
	return mArea;
}

unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
{
	return mSide / 0.25f * 3;
}

unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
{
	unsigned int price = 0;
	switch (fenceType)
	{
	case eFenceType::RED_CEDAR:
		price = mSide * 6 * 3;
		break;
	case eFenceType::SPRUCE:
		price = mSide * 7 * 3;
		break;
	default:
		break;
	}
	return price;
}
