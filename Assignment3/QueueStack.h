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
		virtual ~QueueStack() = default;

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
		queue<stack<T>> mQueueStack;
		double mSum;
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mSum(0.0)
	{
	}

	template<typename T>
	inline QueueStack<T>::QueueStack(const QueueStack<T>& other)
		: mMaxStackSize(other.mMaxStackSize)
		, mQueueStack(other.mQueueStack)
		, mSum(other.mSum)
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
		mQueueStack = rhs.mQueueStack;
		mSum = rhs.mSum;
		return *this;
	}

	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueueStack.front().top();
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T maxNum = numeric_limits<T>::lowest();
		if (mQueueStack.empty())
		{
			return maxNum;
		}

		queue<stack<T>> tmpQuSt;
		while (!mQueueStack.empty())
		{
			stack<T> tmpSt = mQueueStack.front();
			stack<T> tmpSt2;
			while (!tmpSt.empty())
			{
				maxNum = maxNum < tmpSt.top() ? tmpSt.top() : maxNum;
				tmpSt2.push(tmpSt.top());
				tmpSt.pop();
			}
			
			while (!tmpSt2.empty())
			{
				tmpSt.push(tmpSt2.top());
				tmpSt2.pop();
			}
			tmpQuSt.push(tmpSt);
			mQueueStack.pop();
		}

		mQueueStack = tmpQuSt;
		return maxNum;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T minNum = numeric_limits<T>::max();
		if (mQueueStack.empty())
		{
			return minNum;
		}

		queue<stack<T>> tmpQuSt;
		while (!mQueueStack.empty())
		{
			stack<T> tmpSt = mQueueStack.front();
			stack<T> tmpSt2;
			while (!tmpSt.empty())
			{
				minNum = minNum > tmpSt.top() ? tmpSt.top() : minNum;
				tmpSt2.push(tmpSt.top());
				tmpSt.pop();
			}

			while (!tmpSt2.empty())
			{
				tmpSt.push(tmpSt2.top());
				tmpSt2.pop();
			}
			tmpQuSt.push(tmpSt);
			mQueueStack.pop();
		}

		mQueueStack = tmpQuSt;
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
		if (mQueueStack.empty())
		{
			return 0;
		}
		else if (mQueueStack.size() == 1)
		{
			return mQueueStack.front().size();
		}
		else
		{
			return mQueueStack.front().size() + (mQueueStack.size() - 2) * mMaxStackSize + mQueueStack.back().size();
		}
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		return mQueueStack.size();
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		if (mQueueStack.empty() || mQueueStack.back().size() >= mMaxStackSize)
		{
			stack<T> st;
			st.push(number);
			mQueueStack.push(st);
		}
		else
		{
			mQueueStack.back().push(number);
		}
		mSum += static_cast<double>(number);
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T num = mQueueStack.front().top();		
		mQueueStack.front().pop();
		if (mQueueStack.front().empty())
		{
			mQueueStack.pop();
		}
		mSum -= static_cast<double>(num);
		if (mQueueStack.empty())
		{
			mSum = 0.0;
		}

		return num;
	}

	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		return static_cast<T>(mSum);
	}
}