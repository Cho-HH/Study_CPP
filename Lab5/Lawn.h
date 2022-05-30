#pragma once
#include "eGrassType.h"

using namespace lab5;

namespace lab5
{
	class Lawn
	{
	public:
		Lawn(unsigned int area);
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

	private:
		unsigned int mArea;
	};
}