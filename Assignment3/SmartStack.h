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
		virtual ~SmartStack();

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
		stack<T>* mStack;
		stack<T>* mMaxNumStack;
		stack<T>* mMinNumStack;
		T mSum;
		T mSum2;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mStack(new stack<T>)
		, mMaxNumStack(new stack<T>)
		, mMinNumStack(new stack<T>)
		, mSum()
		, mSum2()
	{
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack<T>& other)
		: mStack(new stack<T>(*(other.mStack)))
		, mMaxNumStack(new stack<T>(*(other.mMaxNumStack)))
		, mMinNumStack(new stack<T>(*(other.mMinNumStack)))
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

		*mStack = *(rhs.mStack);
		*mMaxNumStack = *(rhs.mStack);
		*mMinNumStack = *(rhs.mMinNumStack);
		mSum = rhs.mSum;
		mSum2 = rhs.mSum2;

		return *this;
	}

	template<typename T>
	inline SmartStack<T>::~SmartStack()
	{
		delete mStack;
		delete mMaxNumStack;
		delete mMinNumStack;
	}

	template<typename T>
	void assignment3::SmartStack<T>::Push(T number)
	{
		T max = number;
		T min = number;

		if (!mStack->empty())
		{
			max = max < mMaxNumStack->top() ? mMaxNumStack->top() : max;
			min = min > mMinNumStack->top() ? mMinNumStack->top() : min;
		}

		mStack->push(number);
		mMaxNumStack->push(max);
		mMinNumStack->push(min);
		mSum2 += static_cast<T>(pow(number, 2));
		mSum += number;
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T num = mStack->top();
		mSum -= num;
		mSum2 -= static_cast<T>(pow(num, 2));
		mStack->pop();
		mMinNumStack->pop();
		mMaxNumStack->pop();

		return num;
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	inline T SmartStack<T>::Peek()
	{
		return mStack->top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMax()
	{
		return mStack->empty() ? numeric_limits<T>::lowest() : mMaxNumStack->top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		return mStack->empty() ? numeric_limits<T>::max() : mMinNumStack->top();
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		return static_cast<double>(mSum) / static_cast<double>(mStack->size());
	}

	template<typename T>
	inline unsigned int SmartStack<T>::GetCount()
	{
		return mStack->size();
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		auto num = static_cast<int>(mSum2) / static_cast<int>(mStack->size());
		return  num - pow(GetAverage(), 2);
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}
}