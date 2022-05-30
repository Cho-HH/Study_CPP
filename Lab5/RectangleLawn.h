#pragma once
#include "IFenceable.h"
#include "Lawn.h"

class RectangleLawn : public IFenceable, public Lawn
{
public:
	RectangleLawn(unsigned int width, unsigned int height);
	virtual ~RectangleLawn();

	virtual unsigned int GetArea() const;

	virtual unsigned int GetMinimumFencesCount() const;
	virtual unsigned int GetFencePrice(eFenceType fenceType) const;

private:
	unsigned int mWidth;
	unsigned int mHeight;
	unsigned int mArea;
};

