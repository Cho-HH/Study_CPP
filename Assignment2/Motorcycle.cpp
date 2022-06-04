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

	Motorcycle& Motorcycle::operator=(const Motorcycle& rhs)
	{
		Vehicle::operator=(rhs);
		return *this;
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
	void Motorcycle::Move()
	{
		mCurMove++;
		mCurMove % 6 != 0 ? mCurMoveDist++ : mCurMoveDist;
	}
}