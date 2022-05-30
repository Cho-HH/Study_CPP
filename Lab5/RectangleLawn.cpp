#include "RectangleLawn.h"

RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
	: Lawn(width * height)
	, mWidth(width)
	, mHeight(height)
	, mArea(mWidth * mHeight)
{
}

RectangleLawn::~RectangleLawn()
{
}

unsigned int RectangleLawn::GetArea() const
{
	return mArea;
}

unsigned int RectangleLawn::GetMinimumFencesCount() const
{
	unsigned int widthCnt = static_cast<unsigned int>(mWidth / 0.25f);
	unsigned int heightCnt = static_cast<unsigned int>(mHeight / 0.25f);
	return widthCnt * 2 + heightCnt * 2;
}

unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
{
	unsigned int price = 0;
	switch (fenceType)
	{
	case eFenceType::RED_CEDAR:
		price += mWidth * 6 * 2;
		price += mHeight * 6 * 2;
		break;
	case eFenceType::SPRUCE:
		price += mWidth * 7 * 2;
		price += mHeight * 7 * 2;
		break;
	default:
		break;
	}
	return price;
}
