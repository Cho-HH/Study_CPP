#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxCount(maxPassengersCount)
		, mCurIdx(0)
		, mPassengersTotalWeight(0)
		, mCurMove(1)
		, mCurMoveDist(0)
	{
		mPassengers = new const Person*[mMaxCount];
		for (unsigned int i = 0; i < mMaxCount; i++)
		{
			*(mPassengers + i) = nullptr;
		}
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mCurIdx; i++)
		{
			delete *(mPassengers + i);
			*(mPassengers + i) = nullptr;
		}
		delete mPassengers;
		mPassengers = nullptr;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mCurIdx >= mMaxCount)
		{
			return false;
		}
		*(mPassengers + mCurIdx++) = person;
		mPassengersTotalWeight += person->GetWeight();
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (&mPassengers[i] == nullptr || mCurIdx <= i)
		{
			return false;
		}
		mPassengersTotalWeight -= mPassengers[i]->GetWeight();
		delete mPassengers[i];
		mPassengers[i] = nullptr;
		for (unsigned int j = i; j < mMaxCount - 1; j++)
		{
			const Person* tmp = *(mPassengers + j);
			*(mPassengers + j) = *(mPassengers + j + 1);
			*(mPassengers + j + 1) = tmp;
		}
		mCurIdx--;
		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mCurIdx;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxCount;
	}

	unsigned int Vehicle::GetCurMoveDistance() const
	{
		return mCurMoveDist;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		return mCurIdx == 0 ? nullptr : mPassengers[i];
	}
}