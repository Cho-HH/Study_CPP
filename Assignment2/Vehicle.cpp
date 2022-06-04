#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxCount(maxPassengersCount)
		, mCurIdx(0)
		, mPassengersTotalWeight(0)
		, mCurMove(0)
		, mCurMoveDist(0)
		, mbShallowCopy(false)
	{
		mPassengers = new const Person * [mMaxCount];
		for (unsigned int i = 0; i < mMaxCount; i++)
		{
			*(mPassengers + i) = nullptr;
		}
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxCount(other.mMaxCount)
		, mCurIdx(other.mCurIdx)
		, mPassengersTotalWeight(other.mPassengersTotalWeight)
		, mCurMove(other.mCurMove)
		, mCurMoveDist(other.mCurMoveDist)
		, mbShallowCopy(false)
	{
		mPassengers = new const Person*[mMaxCount];
		for (unsigned int i = 0; i < mMaxCount; i++)
		{
			if (i >= mCurIdx)
			{
				*(mPassengers + i) = nullptr;
				continue;
			}

			if (other.mbShallowCopy)
			{
				*(mPassengers + i) = *(other.mPassengers + i);
			}
			else
			{
				Person otherPerson = **(other.mPassengers + i);
				*(mPassengers + i) = new Person(otherPerson.GetName().c_str(), otherPerson.GetWeight());
			}			
		}
	}


	void Vehicle::operator=(const Vehicle& rhs)
	{
		if (mPassengers == rhs.mPassengers)
		{
			return;
		}
		for (unsigned int i = 0; i < mCurIdx; i++)
		{
			delete* (mPassengers + i);
		}
		delete[] mPassengers;
		mMaxCount = rhs.mMaxCount;
		mCurIdx = rhs.mCurIdx;
		mPassengersTotalWeight = rhs.mPassengersTotalWeight;
		mCurMove = rhs.mCurMove;
		mCurMoveDist = rhs.mCurMoveDist;
		mPassengers = new const Person * [mMaxCount];
		for (unsigned int i = 0; i < mMaxCount; i++)
		{
			if (i >= mCurIdx)
			{
				*(mPassengers + i) = nullptr;
				continue;
			}
			Person otherPerson = **(rhs.mPassengers + i);
			*(mPassengers + i) = new Person(otherPerson.GetName().c_str(), otherPerson.GetWeight());
		}
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mCurIdx; i++)
		{
			delete* (mPassengers + i);
			*(mPassengers + i) = nullptr;
		}
		delete[] mPassengers;
		mPassengers = nullptr;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person == nullptr)
		{
			return false;
		}

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
		if (mCurIdx <= i)
		{
			return false;
		}
		mPassengersTotalWeight -= mPassengers[i]->GetWeight();
		delete mPassengers[i];
		mPassengers[i] = nullptr;
		for (unsigned int j = i; j < mCurIdx - 1; j++)
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
		return i >= mCurIdx || mCurIdx == 0 ? nullptr : mPassengers[i];
	}
}