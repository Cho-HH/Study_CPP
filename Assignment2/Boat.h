#pragma once
#include "Airplane.h"
#include "Boatplane.h"
#include "ISailable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		Boat(const Boat& other);
		void operator=(const Boat& rhs);
		virtual ~Boat();

		Boatplane operator+(Airplane& plane);
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetSailSpeed() const;
		virtual void Move();

		void TransferByBoatplane();
	};
}