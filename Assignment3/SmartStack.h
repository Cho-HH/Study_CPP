#pragma once
#include <stack>
#include <cmath>
#include <limits>

using namespace std;

namespace assignment3
{
	template <typename T>
	class SmartStack
	{
	public:
		SmartStack();
		SmartStack(const SmartStack<T>& other);
		SmartStack<T>& operator=(const SmartStack<T>& rhs);
		virtual ~SmartStack() = default;

		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		unsigned int GetCount();
		double GetVariance();
		double GetStandardDeviation();
		void Push(T number);
		T Pop();
		T GetSum();

	private:
		stack<T> mStack;
		stack<T> mMaxNumStack;
		stack<T> mMinNumStack;
		double mSum;
		double mSum2;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mSum(0)
		, mSum2(0)
	{
	}

	template<typename T>
	inline SmartStack<T>::SmartStack(const SmartStack<T>& other)
		: mStack(other.mStack)
		, mMaxNumStack(other.mMaxNumStack)
		, mMinNumStack(other.mMinNumStack)
		, mSum(other.mSum)
		, mSum2(other.mSum2)
	{
	}

	template<typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mStack = rhs.mStack;
		mMaxNumStack = rhs.mStack;
		mMinNumStack = rhs.mMinNumStack;
		mSum = rhs.mSum;
		mSum2 = rhs.mSum2;

		return *this;
	}

	template<typename T>
	void assignment3::SmartStack<T>::Push(T number)
	{
		T max = number;
		T min = number;

		if (!mStack.empty())
		{
			max = max < mMaxNumStack.top() ? mMaxNumStack.top() : max;
			min = min > mMinNumStack.top() ? mMinNumStack.top() : min;
		}

		mStack.push(number);
		mMaxNumStack.push(max);
		mMinNumStack.push(min);
		mSum2 += pow(static_cast<double>(number), 2.0);
		mSum += static_cast<double>(number);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T num = (mStack.top();
		mSum -= static_cast<double>(num);
		mSum2 -= pow(static_cast<double>(num), 2.0);
		mStack.pop();
		mMinNumStack.pop();
		mMaxNumStack.pop();

		if (mStack.empty())
		{
			mSum = 0;
			mSum2 = 0;
		}
		return num;
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		return static_cast<T>(mSum);
	}

	template<typename T>
	inline T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMax()
	{
		return mStack.empty() ? numeric_limits<T>::lowest() : mMaxNumStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		return mStack.empty() ? numeric_limits<T>::max() : mMinNumStack.top();
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		return mSum / static_cast<double>(mStack.size());
	}

	template<typename T>
	inline unsigned int SmartStack<T>::GetCount()
	{
		return mStack.size();
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		return mSum2 / static_cast<double>(mStack.size()) - pow(GetAverage(), 2.0);
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}
}