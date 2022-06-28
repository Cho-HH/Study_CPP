#pragma once
#include <queue>
#include <stack>
#include "SmartSTL.h"

namespace assignment3
{
	template<typename T>
	class QueueStack : public SmartSTL<T>
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack& other) = default;
		QueueStack& operator=(const QueueStack& rhs) = default;
		virtual ~QueueStack() = default;

		virtual T Peek() override;
		virtual T GetMax() override;
		virtual T GetMin() override;
		virtual double GetAverage() override;
		virtual double GetVariance() override;
		virtual unsigned int GetCount() override;

		void Enqueue(T number);
		T Dequeue();

	private:
		unsigned int mMaxStackSize;
		unsigned int mCurStackSize;
		queue<stack<T>> mQueueStack;
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mCurStackSize(0)
	{
	}

	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueueStack.front().top();
	}

	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		return T();
	}

	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		return T();
	}

	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		return static_cast<double>(this->mSum) / static_cast<double>(GetCount());
	}

	template<typename T>
	inline double QueueStack<T>::GetVariance()
	{
		double avr = GetAverage();

		return 0.0;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		return mQueueStack.empty() ? 0 : (mQueueStack.size() - 1) * mMaxStackSize + mQueueStack.back().size();
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mQueueStack.empty() || mCurStackSize >= mMaxStackSize)
		{
			stack<T> st;
			st.push(number);
			mQueueStack.push(st);
			mCurStackSize = 1;
		}
		else
		{
			mQueueStack.back().push(number);
			mCurStackSize++;
		}
		this->mSum += number;
	}

	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		T num = mQueueStack.front().top();
		mQueueStack.front().pop();
		if (mQueueStack.front().empty())
		{
			mQueueStack.pop();
		}
		this->mSum -= num;
		return num;
	}
}


