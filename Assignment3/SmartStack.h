#pragma once
#include <stack>
#include "SmartSTL.h"

namespace assignment3
{
	template <typename T>
	class SmartStack final : public SmartSTL<T>
	{
	public:
		SmartStack();
		SmartStack(const SmartStack<T>& other);
		SmartStack<T>& operator=(const SmartStack<T>& rhs);
		virtual ~SmartStack();

		virtual T Peek() override;
		virtual T GetMax() override;
		virtual T GetMin() override;
		virtual double GetAverage() override;
		virtual unsigned int GetCount() override;
		virtual double GetVariance() override;

		void Push(T number);
		T Pop();

	private:
		stack<T>* mStack;
		stack<T>* mMaxNumStack;
		stack<T>* mMinNumStack;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: SmartSTL<T>()
		, mStack(new stack<T>)
		, mMaxNumStack(new stack<T>)
		, mMinNumStack(new stack<T>)
	{
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack<T>& other)
		: SmartSTL<T>(other)
		, mStack(new stack<T>)
		, mMaxNumStack(new stack<T>)
		, mMinNumStack(new stack<T>)
	{	
		*mStack = *(other.mStack);
		*mMaxNumStack = *(other.mMaxNumStack);
		*mMinNumStack = *(other.mMinNumStack);
	}

	template<typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		SmartSTL<T>::operator=(rhs);

		*mStack = *(rhs.mStack);
		*mMaxNumStack = *(rhs.mStack);
		*mMinNumStack = *(rhs.mMinNumStack);

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
		this->mSum2 += static_cast<T>(pow(number, 2));
		this->mSum += number;
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T num = mStack->top();
		this->mSum -= num;
		this->mSum2 -= static_cast<T>(pow(num, 2));
		mStack->pop();
		mMinNumStack->pop();
		mMaxNumStack->pop();

		if (mStack->empty())
		{
			this->mSum = T();
			this->mSum2 = T();
		}
		return num;
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
		return static_cast<double>(this->mSum) / static_cast<double>(mStack->size());
	}

	template<typename T>
	inline unsigned int SmartStack<T>::GetCount()
	{
		return mStack->size();
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		return static_cast<double>(this->mSum2) / static_cast<double>(mStack->size()) - pow(GetAverage(), 2);
	}
}