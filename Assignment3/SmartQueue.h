#pragma once
#include <queue>
#include "SmartSTL.h"

namespace assignment3
{
	template <typename T>
	class SmartQueue  : public SmartSTL<T>
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue<T>& other);
		SmartQueue<T>& operator=(const SmartQueue<T>& rhs);
		virtual ~SmartQueue();

		virtual T Peek() override;
		virtual T GetMax() override;
		virtual T GetMin() override;
		virtual double GetAverage() override;
		virtual double GetVariance() override;
		virtual unsigned int GetCount() override;

		void Enqueue(T number);
		T Dequeue();

	private:
		queue<T>* mQueue;
	};


	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: SmartSTL<T>()
		, mQueue(new queue<T>)
	{
	}

	template<typename T>
	inline SmartQueue<T>::SmartQueue(const SmartQueue<T>& other)
		: SmartSTL<T>(other)
		, mQueue(new queue<T>)
	{
		*mQueue = *(other.mQueue);
	}

	template<typename T>
	inline SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		SmartSTL<T>::operator=(rhs);
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
		this->mSum2 += static_cast<T>(pow(number, 2));
		this->mSum += number;
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T num = mQueue->front();
		this->mSum -= num;
		this->mSum2 -= static_cast<T>(pow(num, 2));
		mQueue->pop();
		return num;
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
		return static_cast<double>(this->mSum) / static_cast<double>(mQueue->size());
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		//ºÐ»ê
		return static_cast<double>(this->mSum2) / static_cast<double>(mQueue->size()) - pow(GetAverage(), 2);
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue->size();
	}
}

