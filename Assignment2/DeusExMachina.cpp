#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = nullptr;

	DeusExMachina::DeusExMachina()
		: mCurVehiclesCnt(0)
	{
		for (unsigned int i = 0; i < 10; i++)
		{
			*(mVehicles + i) = nullptr;
		}
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance == nullptr)
		{
			mInstance = new DeusExMachina();				
		}
		return mInstance;
	}

	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int i = 0; i < mCurVehiclesCnt; i++)
		{
			delete *(mVehicles + i);
		}
		if (mInstance != nullptr)
		{
			delete mInstance;
		}
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mCurVehiclesCnt; i++)
		{
			(*(mVehicles + i))->IsMove();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mCurVehiclesCnt >= 10)
		{
			return false;
		}

		mVehicles[mCurVehiclesCnt++] = vehicle;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mCurVehiclesCnt)
		{
			return false;
		}

		delete mVehicles[i];
		mVehicles[i] = nullptr;
		for (unsigned int j = i; j < mCurVehiclesCnt - 1; j++)
		{
			Vehicle* tmp = *(mVehicles + j);
			*(mVehicles + j) = *(mVehicles + j + 1);
			*(mVehicles + j) = tmp;
		}
		mCurVehiclesCnt--;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mCurVehiclesCnt == 0)
		{
			return nullptr;
		}

		unsigned int furthestDistance = 0;
		unsigned int furthestIdx = 0;
		for (unsigned int i = 0; i < mCurVehiclesCnt; i++)
		{
			unsigned int dist = (*(mVehicles + i))->GetCurMoveDistance() * (*(mVehicles + i))->GetMaxSpeed();
			if (furthestDistance < dist)
			{
				furthestDistance = dist;
				furthestIdx = i;
			}
		}
		return furthestDistance == 0 ? mVehicles[0] : mVehicles[furthestIdx];
	}
}