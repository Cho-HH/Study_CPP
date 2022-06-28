#pragma once
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue<T>& other);
		SmartQueue<T>& operator=(const SmartQueue<T>& rhs);
		virtual ~SmartQueue();

		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		double GetVariance();
		unsigned int GetCount();
		double GetStandardDeviation();
		void Enqueue(T number);
		T Dequeue();
		T GetSum();

	private:
		queue<T>* mQueue;
		T mSum;
		T mSum2;
	};


	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mQueue(new queue<T>)
		, mSum()
		, mSum2()
	{
	}

	template<typename T>
	inline SmartQueue<T>::SmartQueue(const SmartQueue<T>& other)
		: mQueue(new queue<T>(*(other.mQueue)))
		, mSum()
		, mSum2()
	{
	}

	template<typename T>
	inline SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		*mQueue = *(rhs.mQueue);
		return *this;
	}

	template<typename T>
	inline SmartQueue<T>::~SmartQueue()
	{
		delete mQueue;
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		mQueue->push(number);
		mSum2 += static_cast<T>(pow(number, 2));
		mSum += number;
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T num = mQueue->front();
		mSum -= num;
		mSum2 -= static_cast<T>(pow(num, 2));
		mQueue->pop();
		return num;
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		return mSum;
	}


	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		return mQueue->front();
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		T maxNum = numeric_limits<T>::lowest();
		if (mQueue->empty())
		{
			return maxNum;
		}

		queue<T> tmpQu;
		while (!mQueue->empty())
		{
			T num = mQueue->front();
			maxNum = maxNum < num ? num : maxNum;
			mQueue->pop();
			tmpQu.push(num);
		}
		*mQueue = tmpQu;		
		return maxNum;
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		T minNum = numeric_limits<T>::max();
		if (mQueue->empty())
		{
			return minNum;
		}

		queue<T> tmpQu;
		while (!mQueue->empty())
		{
			T num = mQueue->front();
			minNum = minNum > num ? num : minNum;
			mQueue->pop();
			tmpQu.push(num);
		}
		*mQueue = tmpQu;
		return minNum;
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		return static_cast<double>(mSum) / static_cast<double>(mQueue->size());
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		//ºÐ»ê
		return static_cast<double>(mSum2) / static_cast<double>(mQueue->size()) - pow(GetAverage(), 2);
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue->size();
	}
	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}
}

