#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::UBoat(const UBoat& other)
		: Vehicle(other)
	{
	}

	void UBoat::operator=(const UBoat& rhs)
	{
		Vehicle::operator=(rhs);
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		return GetDiveSpeed() >= GetSailSpeed() ? GetDiveSpeed() : GetSailSpeed();
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		unsigned int tmp = static_cast<unsigned int>(std::log(static_cast<double>(mPassengersTotalWeight + 150) / 150) + 0.5);
		return 500 * tmp + 30;
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		int s = static_cast<int>((550 - static_cast<double>(mPassengersTotalWeight) / 10) + 0.5);
		return std::max(s, 200);
	}
	void UBoat::IsMove()
	{
		mCurMove % 6 == 1 || mCurMove % 6 == 2 ? mCurMoveDist++ : mCurMoveDist;
		mCurMove++;
	}
}