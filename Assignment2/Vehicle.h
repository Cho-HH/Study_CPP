#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;
		virtual void IsMove() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetCurMoveDistance() const;

	protected:
		unsigned int mMaxCount;
		const Person** mPassengers;
		unsigned int mCurIdx;
		unsigned int mPassengersTotalWeight;
		unsigned int mCurMove;
		unsigned int mCurMoveDist;
	};
}