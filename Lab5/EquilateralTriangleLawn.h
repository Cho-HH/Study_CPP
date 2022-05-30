#pragma once
#include <cmath>
#include "IFenceable.h"
#include "Lawn.h"

namespace lab5
{
	class EquilateralTriangleLawn : public IFenceable, public Lawn
	{
	public:
		EquilateralTriangleLawn(unsigned int side);
		//EquilateralTriangleLawn& operator=(const EquilateralTriangleLawn& rhs);
		virtual ~EquilateralTriangleLawn();

		virtual unsigned int GetArea() const;

		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mSide;
		unsigned int mArea;
	};
}


