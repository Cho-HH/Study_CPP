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
		void operator=(const Sedan& rhs);
		virtual ~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		bool IsTrailer() const;

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		virtual void IsMove();

	private:
		bool bTrailer;
		const Trailer* mTrailer;
	};
}