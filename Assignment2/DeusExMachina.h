#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		virtual ~DeusExMachina();

		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		DeusExMachina();
		static DeusExMachina* mInstance;
		Vehicle* mVehicles[10];
		unsigned int mCurVehiclesCnt;
	};
}