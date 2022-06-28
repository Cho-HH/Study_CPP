#pragma once
#include <stack>
#include <queue>
#include "SmartSTL.h"

namespace assignment3
{
	template<typename T>
	class QueueStack final : public SmartSTL<T>
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack<T>& other);
		QueueStack<T>& operator=(const QueueStack<T>& rhs);
		virtual ~QueueStack();

		virtual T Peek() override;
		virtual T GetMax() override;
		virtual T GetMin() override;
		virtual double GetAverage() override;
		virtual double GetVariance() override;
		virtual unsigned int GetCount() override;

		unsigned int GetStackCount();
		void Enqueue(T number);
		T Dequeue();

	private:
		unsigned int mMaxStackSize;
		unsigned int mCurStackSize;
		queue<stack<T>>* mQueueStack;
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: SmartSTL<T>()
		, mMaxStackSize(maxStackSize)
		, mCurStackSize(0)
		, mQueueStack(new queue<stack<T>>)
	{
	}

	template<typename T>
	inline QueueStack<T>::QueueStack(const QueueStack<T>& other)
		: SmartSTL<T>(other)
		, mMaxStackSize(other.mMaxStackSize)
		, mCurStackSize(other.mCurStackSize)
		, mQueueStack(new queue<stack<T>>)
	{
		*mQueueStack = *(other.mQueueStack);
	}

	template<typename T>
	inline QueueStack<T>& QueueStack<T>::operator=(const QueueStack<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		SmartSTL<T>::operator=(rhs);
		mMaxStackSize = rhs.mMaxStackSize;
		mCurStackSize = rhs.mCurStackSize;
		*mQueueStack = *(rhs.mQueueStack);
		return *this;
	}

	template<typename T>
	inline QueueStack<T>::~QueueStack()
	{
		delete mQueueStack;
	}

	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueueStack->front().top();
	}

	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		T maxNum = numeric_limits<T>::lowest();
		if (mQueueStack->empty())
		{
			return maxNum;
		}

		//queue<stack<T>> tmpQuSt;
		//while (!mQueueStack->empty())
		//{

		//	T num = mQueue->front();
		//	maxNum = maxNum < num ? num : maxNum;
		//	mQueue->pop();
		//	tmpQu.push(num);
		//}
		//*mQueue = tmpQu;
		return maxNum;
	}

	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		T minNum = numeric_limits<T>::max();
		if (mQueueStack->empty())
		{
			return minNum;
		}
		return minNum;
	}

	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		return static_cast<double>(this->mSum) / static_cast<double>(GetCount());
	}

	template<typename T>
	inline double QueueStack<T>::GetVariance()
	{
		return static_cast<double>(this->mSum2) / static_cast<double>(GetCount()) - pow(GetAverage(), 2);
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		if (mQueueStack->empty())
		{
			return 0;
		}
		else if (mQueueStack->size() == 1)
		{
			return mQueueStack->front().size();
		}
		else
		{
			return mQueueStack->front().size() + (mQueueStack->size() - 2) * mMaxStackSize + mQueueStack->back().size();
		}
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		return mQueueStack->size();
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		if (mQueueStack->empty() || mCurStackSize >= mMaxStackSize)
		{
			stack<T> st;
			st.push(number);
			mQueueStack->push(st);
			mCurStackSize = 1;
		}
		else
		{
			mQueueStack->back().push(number);
			mCurStackSize++;
		}
		this->mSum2 += static_cast<T>(pow(number, 2));
		this->mSum += number;
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T num = mQueueStack->front().top();
		mQueueStack->front().pop();
		if (mQueueStack->front().empty())
		{
			mQueueStack->pop();
		}
		this->mSum2 -= static_cast<T>(pow(num, 2));
		this->mSum -= num;
		return num;
	}
}


