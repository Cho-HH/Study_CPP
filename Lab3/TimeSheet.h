#pragma once
#include <string>

using namespace std;

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& other);
		~TimeSheet();

		TimeSheet& operator= (const TimeSheet& rhs);

		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		string mName;
		unsigned int* mEntries;
		unsigned int mCurEntry;
		unsigned int mMaxEntries;
	};
}