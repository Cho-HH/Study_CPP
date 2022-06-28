#pragma once
#include <stack>
#include <queue>
#include <limits>

using namespace std;

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack<T>& other);
		QueueStack<T>& operator=(const QueueStack<T>& rhs);
		virtual ~QueueStack();

		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		unsigned int GetCount();
		unsigned int GetStackCount();
		void Enqueue(T number);
		T Dequeue();
		T GetSum();

	private:
		unsigned int mMaxStackSize;
		unsigned int mCurStackSize;
		queue<stack<T>>* mQueueStack;
		T mSum;
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mCurStackSize(0)
		, mQueueStack(new queue<stack<T>>)
		, mSum()
	{
	}

	template<typename T>
	inline QueueStack<T>::QueueStack(const QueueStack<T>& other)
		: mMaxStackSize(other.mMaxStackSize)
		, mCurStackSize(other.mCurStackSize)
		, mQueueStack(new queue<stack<T>>(*(other.mQueueStack)))
		, mSum()
	{
	}

	template<typename T>
	inline QueueStack<T>& QueueStack<T>::operator=(const QueueStack<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		mMaxStackSize = rhs.mMaxStackSize;
		mCurStackSize = rhs.mCurStackSize;
		*mQueueStack = *(rhs.mQueueStack);
		mSum = rhs.mSum;
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
		return T();
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
		return static_cast<double>(mSum) / static_cast<double>(GetCount());
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
		mSum += number;
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
		mSum -= num;
		return num;
	}

	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		return mSum;
	}
}


