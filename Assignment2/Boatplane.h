#pragma once
#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Airplane;
	class Boat;

	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(unsigned int maxPassengersCount, Airplane& plane, Boat& boat);
		Boatplane(const Boatplane& rhs);

		void operator=(const Boatplane& rhs);
		
		virtual ~Boatplane();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetSailSpeed() const;

		virtual void Move();

		void SetShallowCopy();
	};
}