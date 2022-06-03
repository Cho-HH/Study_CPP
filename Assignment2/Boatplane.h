#pragma once
#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
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