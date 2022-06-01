#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		return std::max(static_cast<unsigned int>(pow(-1 * (static_cast<double>(mPassengersTotalWeight) / 15), 3) + 2 * static_cast<double>(mPassengersTotalWeight) + 400 + 0.5), static_cast<unsigned int>(0));
	}
	void Motorcycle::IsMove()
	{
		mCurMove % 6 != 0 ? mCurMoveDist++ : mCurMoveDist;
		mCurMove++;
	}
}