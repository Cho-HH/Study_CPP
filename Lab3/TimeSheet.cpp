#include <cmath>
#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mCurEntry(0)
		, mMaxEntries(maxEntries)
		, mName(name)
	{
		mEntries = new unsigned int[maxEntries];
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		: mCurEntry(other.mCurEntry)
		, mMaxEntries(other.mMaxEntries)
		, mName(other.mName)
	{
		mEntries = new unsigned int[mMaxEntries];
		memcpy(mEntries, other.mEntries, mMaxEntries * sizeof(int));
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}
		mCurEntry = rhs.mCurEntry;
		mMaxEntries = rhs.mMaxEntries;
		mName = rhs.mName;
		mEntries = new unsigned int[mMaxEntries];
		memcpy(mEntries, rhs.mEntries, mMaxEntries * sizeof(int));
		return *this;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mEntries;
		mEntries = nullptr;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours > 10 || timeInHours < 1)
		{
			return;
		}

		if (mCurEntry >= mMaxEntries)
		{
			return;
		}

		mEntries[mCurEntry++] = timeInHours;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (mCurEntry <= index)
		{
			return -1;
		}
		return mEntries[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int total = 0;
		for (int i = 0; i < mCurEntry; i++)
		{
			total += mEntries[i];
		}
		return total;
	}

	float TimeSheet::GetAverageTime() const
	{
		if (mCurEntry == 0)
		{
			return 0.0f;
		}

		int total = 0;
		for (int i = 0; i < mCurEntry; i++)
		{
			total += mEntries[i];
		}
		return (float)total / (float)mCurEntry;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float avr = GetAverageTime();
		if (avr == 0.0f)
		{
			return 0.0f;
		}
		float va = 0.0f;
		for (int i = 0; i < mCurEntry; i++)
		{
			va += pow(mEntries[i] - avr, 2);
		}
		va /= mCurEntry;
		return sqrt(va);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}