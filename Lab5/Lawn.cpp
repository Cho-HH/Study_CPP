#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn(unsigned int area)
		: mArea(area)
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		unsigned int price = 0;
		switch (grassType)
		{
		case eGrassType::BAHIA:
			price = mArea * 5;
			break;
		case eGrassType::BENTGRASS:
			price = mArea * 3;
			break;
		case eGrassType::BERMUDA:
			price = mArea * 8;
			break;
		case eGrassType::PERENNIAL_RYEGRASS:
			price = static_cast<unsigned int>(mArea * 2.5 + 0.5);
			break;
		case eGrassType::ST_AUGUSTINE:
			price = static_cast<unsigned int>(mArea * 4.5 + 0.5);
			break;
		default:
			break;
		}
		return price;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double tmp = static_cast<double>(mArea) / 0.3f;
		unsigned int uiTmp = static_cast<unsigned int>(tmp);
		return uiTmp == tmp ? uiTmp : uiTmp + 1;
	}
}