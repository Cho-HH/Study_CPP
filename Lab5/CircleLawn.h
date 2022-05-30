#pragma once
#include "Lawn.h"

class CircleLawn : public Lawn
{
public:
	CircleLawn(unsigned int radius);
	virtual ~CircleLawn();

	virtual unsigned int GetArea() const;

private:
	unsigned int mArea;
};

