#include "Airplane.h"
#include "Boat.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{		
	}

	Airplane::Airplane(const Airplane& other)
		: Vehicle(other.mMaxCount)
	{
	}

	void Airplane::operator=(const Airplane& rhs)
	{
		if (mPassengers == rhs.mPassengers)
		{
			return;
		}

		for (unsigned int i = 0; i < mCurIdx; i++)
		{
			delete *(mPassengers + i);
			*(mPassengers + i) = nullptr;
		}

		for (unsigned int i = 0; i < rhs.mCurIdx; i++)
		{
			*(mPassengers + i) = new Person(rhs.GetPassenger(i)->GetName().c_str(), rhs.GetPassenger(i)->GetWeight());
		}
		mMaxCount = rhs.mMaxCount;
		mCurIdx = rhs.mCurIdx;
		mPassengersTotalWeight = rhs.mPassengersTotalWeight;
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		static Boatplane bp(mMaxCount + boat.GetMaxPassengersCount());
		for (unsigned int i = 0; i < mCurIdx; i++)
		{			
			bp.AddPassenger(*(mPassengers + i));			
		}
		for (unsigned int i = 0; i < boat.GetPassengersCount(); i++)
		{			
			bp.AddPassenger(boat.GetPassenger(i));			
		}
		TransferByBoatplane();
		boat.TransferByBoatplane();
		return bp;
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		return GetFlySpeed() >= GetDriveSpeed() ? GetFlySpeed() : GetDriveSpeed();
	}

	unsigned int Airplane::GetFlySpeed() const
	{	
		double tmp = static_cast<double>(-1 * mPassengersTotalWeight + 800) / 500;
		return static_cast<unsigned int>(200 * pow(M_E, tmp) + 0.5);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		double tmp = static_cast<double>(-1 * mPassengersTotalWeight + 400) / 70;
		return static_cast<unsigned int>(4 * pow(M_E, tmp) + 0.5);
	}

	void Airplane::IsMove() 
	{
		mCurMove % 4 == 1 ? mCurMoveDist++ : mCurMoveDist;
		mCurMove++;
	}

	void Airplane::TransferByBoatplane()
	{
		for (unsigned int i = 0; i < mCurIdx; i++)
		{
			*(mPassengers + i) = nullptr;
		}
		mCurIdx = 0;
		mPassengersTotalWeight = 0;
	}
}