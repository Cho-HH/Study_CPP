#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, bTrailer(false)
		, mTrailer(nullptr)
	{
	}

	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
		, bTrailer(other.bTrailer)
	{
		mTrailer = new Trailer(other.mTrailer->GetWeight());
	}

	void Sedan::operator=(const Sedan& rhs)
	{
		Vehicle::operator=(rhs);
		if (bTrailer)
		{
			delete mTrailer;
		}
		bTrailer = rhs.bTrailer;
		mTrailer = new Trailer(rhs.mTrailer->GetWeight());
	}

	Sedan::~Sedan()
	{
		if (mTrailer != nullptr)
		{
			delete mTrailer;
		}
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (bTrailer)
		{
			return false;
		}

		mTrailer = trailer;
		bTrailer = true;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (bTrailer)
		{
			delete mTrailer;
			mTrailer = nullptr;
			bTrailer = false;
			return true;
		}
		return false;
	}

	bool Sedan::IsTrailer() const
	{
		return mTrailer;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int trailerWeight = bTrailer ? mTrailer->GetWeight() : 0;
		unsigned int totalWeight = mPassengersTotalWeight + trailerWeight;
		unsigned int speed = 0;
		if (totalWeight <= 80)
		{
			speed = 480;
		}
		else if (totalWeight > 350)
		{
			speed = 300;
		}
		else if (totalWeight > 260)
		{
			speed = 380;
		}
		else if (totalWeight > 160)
		{
			speed = 400;
		}
		else 
		{
			speed = 458;
		}
		return speed;
	}

	void Sedan::IsMove()
	{
		if (bTrailer)
		{
			mCurMove % 7 != 0 || mCurMove % 7 != 6 ? mCurMoveDist++ : mCurMoveDist;
		}
		else
		{
			mCurMove % 6 != 0 ? mCurMoveDist++ : mCurMoveDist;
		}
		mCurMove++;
	}
}