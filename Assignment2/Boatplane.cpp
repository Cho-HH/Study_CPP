#include "Boatplane.h"
#include "Boat.h"
#include "Airplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::Boatplane(unsigned int maxPassengersCount, Airplane& plane, Boat& boat)
		: Vehicle(maxPassengersCount)
	{
		for (unsigned int i = 0; i < plane.GetPassengersCount(); i++)
		{
			AddPassenger(plane.GetPassenger(i));
		}
		for (unsigned int i = 0; i < boat.GetPassengersCount(); i++)
		{
			AddPassenger(boat.GetPassenger(i));
		}
		plane.TransferByBoatplane();
		boat.TransferByBoatplane();
		//SetShallowCopy();
	}

	Boatplane::Boatplane(const Boatplane& rhs)
		: Vehicle(rhs)
	{
	}

	Boatplane& Boatplane::operator=(const Boatplane& rhs)
	{
		Vehicle::operator=(rhs);
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
		double tmp = static_cast<double>(static_cast<int>(-1 * mPassengersTotalWeight) + 500) / 300;
		tmp = pow(E, tmp);
		return static_cast<unsigned int>(150 * tmp + 0.5);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		int s = static_cast<int>(800 - 1.7 * static_cast<double>(mPassengersTotalWeight) + 0.5);
		return std::max(s, 20);
	}

	void Boatplane::Move()
	{
		mCurMove++;
		mCurMove % 4 == 1 ? mCurMoveDist++ : mCurMoveDist;
	}
	void Boatplane::SetShallowCopy()
	{
		mbShallowCopy = true;
	}
}