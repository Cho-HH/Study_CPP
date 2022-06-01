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

	Boatplane& Boatplane::operator=(const Boatplane& rhs)
	{
		if (*mPassengers == *(rhs.mPassengers))
		{
			return *this;
		}

		for (unsigned int i = 0; i < mCurIdx; i++)
		{
			delete* (mPassengers + i);
			*(mPassengers + i) = nullptr;
		}

		for (unsigned int i = 0; i < rhs.mCurIdx; i++)
		{
			*(mPassengers + i) = new Person(rhs.GetPassenger(i)->GetName().c_str(), rhs.GetPassenger(i)->GetWeight());
		}	
		mMaxCount = rhs.mMaxCount;
		mCurIdx = rhs.mCurIdx;
		return *this;
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
		return static_cast<unsigned int>(150 * pow(M_E, tmp) + 0.5);
	}
	unsigned int Boatplane::GetSailSpeed() const
	{
		return std::max(static_cast<unsigned int>(800 - 1.7 * static_cast<double>(mPassengersTotalWeight) + 0.5), static_cast<unsigned int>(20));
	}
	void Boatplane::IsMove()
	{
		mCurMove % 4 == 1 ? mCurMoveDist++ : mCurMoveDist;
		mCurMove++;
	}
}