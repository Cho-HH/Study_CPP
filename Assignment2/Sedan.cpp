#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mbTrailer(false)
		, mTrailer(nullptr)
	{
	}

	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
		, mbTrailer(other.mbTrailer)
	{
		mTrailer = new Trailer(other.mTrailer->GetWeight());
	}

	Sedan& Sedan::operator=(const Sedan& rhs)
	{
		Vehicle::operator=(rhs);
		if (this == &rhs)
		{
			return *this;
		}

		if (mbTrailer)
		{
			delete mTrailer;
		}
		mbTrailer = rhs.mbTrailer;
		mTrailer = new Trailer(rhs.mTrailer->GetWeight());
		return *this;
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
		if (mbTrailer)
		{
			return false;
		}

		mTrailer = trailer;
		mbTrailer = true;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mbTrailer)
		{
			delete mTrailer;
			mTrailer = nullptr;
			mbTrailer = false;
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
		unsigned int trailerWeight = mbTrailer ? mTrailer->GetWeight() : 0;
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

	void Sedan::Move()
	{
		mCurMove++;
		if (mbTrailer)
		{
			mCurMove % 7 != 0 || mCurMove % 7 != 6 ? mCurMoveDist++ : mCurMoveDist;
		}
		else
		{
			mCurMove % 6 != 0 ? mCurMoveDist++ : mCurMoveDist;
		}
	}
}