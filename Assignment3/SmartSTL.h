#pragma once
#include <cmath>
#include <limits>
#include <cassert>

using namespace std;

namespace assignment3
{
	template <typename T>
	class SmartSTL
	{
	public:
		SmartSTL();
		SmartSTL(const SmartSTL<T>& other);
		SmartSTL& operator=(const SmartSTL& rhs);
		virtual ~SmartSTL() = default;

		virtual T Peek() = 0;
		virtual T GetMax() = 0;
		virtual T GetMin() = 0;
		T GetSum();

		virtual double GetAverage() = 0;		
		virtual unsigned int GetCount() = 0;
		virtual double GetVariance() = 0;
		
		double GetStandardDeviation();

	protected:
		T mSum;
		T mSum2;
	};

	template<typename T>
	inline SmartSTL<T>::SmartSTL()
		: mSum()
		, mSum2()
	{
	}

	template<typename T>
	inline SmartSTL<T>::SmartSTL(const SmartSTL<T>& other)
	{
		mSum = other.mSum;
		mSum2 = other.mSum2;
	}

	template<typename T>
	inline SmartSTL<T>& SmartSTL<T>::operator=(const SmartSTL<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		mSum = rhs.mSum;
		mSum2 = rhs.mSum2;
		return *this;
	}

	template<typename T>
	inline T SmartSTL<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	inline double SmartSTL<T>::GetStandardDeviation()
	{
		//표준편차 (루트 분산)
		return sqrt(GetVariance());
	}
}

