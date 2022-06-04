#pragma once
#include "IDivable.h"
#include "ISailable.h"
#include "Vehicle.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		UBoat(const UBoat& other);
		UBoat& operator=(const UBoat& rhs);
		~UBoat();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDiveSpeed() const;
		virtual unsigned int GetSailSpeed() const;

		virtual void Move();
	};
}