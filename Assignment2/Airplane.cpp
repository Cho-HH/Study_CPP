#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{		
	}

	Airplane::Airplane(const Airplane& other)
		: Vehicle(other)		
	{
	}

	Airplane& Airplane::operator=(const Airplane& rhs)
	{		
		Vehicle::operator=(rhs);
		return *this;
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		return Boatplane(mMaxCount + boat.GetMaxPassengersCount(), *this, boat);
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		return GetFlySpeed() >= GetDriveSpeed() ? GetFlySpeed() : GetDriveSpeed();
	}

	unsigned int Airplane::GetFlySpeed() const
	{	
		double tmp = static_cast<double>(-1 * mPassengersTotalWeight + 800) / 500;
		return static_cast<unsigned int>(200 * pow(E, tmp) + 0.5);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		double tmp = static_cast<double>(-1 * mPassengersTotalWeight + 400) / 70;
		return static_cast<unsigned int>(4 * pow(E, tmp) + 0.5);
	}

	void Airplane::Move() 
	{
		mCurMove++;
		mCurMove % 4 == 1 ? mCurMoveDist++ : mCurMoveDist;
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