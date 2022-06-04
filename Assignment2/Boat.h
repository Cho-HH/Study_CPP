#pragma once
#include "ISailable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Airplane;
	class Boatplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		Boat(const Boat& other);
		Boat& operator=(const Boat& rhs);
		virtual ~Boat();

		Boatplane operator+(Airplane& plane);
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetSailSpeed() const;
		virtual void Move();

		void TransferByBoatplane();
	};
}