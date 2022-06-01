#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		unsigned int totalWeight = 0;
		for (unsigned int i = 0; i < mCurIdx; i++)
		{
			totalWeight += (*(mPassengers + i))->GetWeight();
		}
	}

	Boatplane::Boatplane(const Boatplane& rhs)
		: Vehicle(rhs)
	{
	}

	void Boatplane::operator=(const Boatplane& rhs)
	{
		Vehicle::operator=(rhs);
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		return GetFlySpeed() >= GetSailSpeed() ? GetFlySpeed() : GetSailSpeed();
	}
	unsigned int Boatplane::GetFlySpeed() const
	{
		double tmp = static_cast<double>(-1 * mPassengersTotalWeight + 500) / 300;
		return static_cast<unsigned int>(150 * pow(E, tmp) + 0.5);
	}
	unsigned int Boatplane::GetSailSpeed() const
	{
		int s = static_cast<int>(800 - 1.7 * static_cast<double>(mPassengersTotalWeight) + 0.5);
		return std::max(s, 20);
	}
	void Boatplane::IsMove()
	{
		mCurMove % 4 == 1 ? mCurMoveDist++ : mCurMoveDist;
		mCurMove++;
	}
}