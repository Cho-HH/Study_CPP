#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{		
	}

	Boat::Boat(const Boat& other)
		: Vehicle(other)
	{
	}

	void Boat::operator=(const Boat& rhs)
	{
		Vehicle::operator=(rhs);
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		static Boatplane bp(mMaxCount + plane.GetMaxPassengersCount());
		for (unsigned int i = 0; i < mCurIdx; i++)
		{
			bp.AddPassenger(*(mPassengers + i));
		}
		for (unsigned int i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp.AddPassenger(plane.GetPassenger(i));
		}
		TransferByBoatplane();
		plane.TransferByBoatplane();
		return bp;
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		int s = static_cast<int>(800 - 10 * mPassengersTotalWeight);
		return std::max(s, 20);
	}

	void Boat::Move()
	{
		mCurMove++;
		mCurMove % 3 != 0 ? mCurMoveDist++ : mCurMoveDist;
	}

	void Boat::TransferByBoatplane()
	{
		for (unsigned int i = 0; i < mCurIdx; i++)
		{
			*(mPassengers + i) = nullptr;
		}
		mCurIdx = 0;
		mPassengersTotalWeight = 0;
	}
}