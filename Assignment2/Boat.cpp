#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{		
	}

	Boat& Boat::operator=(const Boat& rhs)
	{
		if (mPassengers == rhs.mPassengers)
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
		mPassengersTotalWeight = rhs.mPassengersTotalWeight;
		return *this;
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
		return std::max(800 - 10 * mPassengersTotalWeight, static_cast<unsigned int>(20));
	}

	void Boat::IsMove()
	{
		mCurMove % 3 != 0 ? mCurMoveDist++ : mCurMoveDist;
		mCurMove++;
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