#pragma once
#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int radius);
		virtual ~CircleLawn();

		virtual unsigned int GetArea() const;
	};
}


