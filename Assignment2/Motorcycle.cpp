#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::Motorcycle(const Motorcycle& other)
		: Vehicle(other)
	{
	}

	void Motorcycle::operator=(const Motorcycle& rhs)
	{
		Vehicle::operator=(rhs);
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
		int s = static_cast<int>(pow(-1 * (static_cast<double>(mPassengersTotalWeight) / 15), 3) + 2 * mPassengersTotalWeight + 400 + 0.5);
		return std::max(s, 0);
	}
	void Motorcycle::IsMove()
	{
		mCurMove % 6 != 0 ? mCurMoveDist++ : mCurMoveDist;
		mCurMove++;
	}
}