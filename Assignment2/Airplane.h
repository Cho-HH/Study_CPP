#pragma once
#include "IDrivable.h"
#include "IFlyable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Boat;
	class Boatplane;

	class Airplane : public Vehicle, public IDrivable, public IFlyable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		Airplane(const Airplane& other);
		Airplane& operator=(const Airplane& rhs);
		virtual ~Airplane();

		Boatplane operator+(Boat& boat);

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		virtual void Move();

		void TransferByBoatplane();
	};
}