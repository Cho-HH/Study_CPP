#pragma once
#include "Trailer.h"
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& other);
		Sedan& operator=(const Sedan& rhs);
		virtual ~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		bool IsTrailer() const;

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		virtual void Move();

	private:
		bool mbTrailer;
		const Trailer* mTrailer;
	};
}