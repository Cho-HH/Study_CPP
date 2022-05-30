#pragma once
#include "RectangleLawn.h"

class SquareLawn : public RectangleLawn
{
public:
	SquareLawn(unsigned int width);
	virtual ~SquareLawn();
};

