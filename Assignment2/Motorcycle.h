#pragma once
#include "IDrivable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Motorcycle : public IDrivable, public Vehicle
	{
	public:
		Motorcycle();
		virtual ~Motorcycle();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		virtual void IsMove();
	};
}