#pragma once
#include <queue>
#include "SmartSTL.h"

namespace assignment3
{
	template <typename T>
	class SmartQueue  : public SmartSTL<T>
	{
	public:
		SmartQueue() = default;
		SmartQueue(const SmartQueue& other) = default;
		SmartQueue& operator=(const SmartQueue& rhs) = default;
		virtual ~SmartQueue() = default;

		virtual T Peek() override;
		virtual T GetMax() override;
		virtual T GetMin() override;
		virtual double GetAverage() override;
		virtual double GetVariance() override;
		virtual unsigned int GetCount() override;

		void Enqueue(T number);
		T Dequeue();

	private:
		queue<T> mQueue;
	};

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
		this->mSum += number;
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T num = mQueue.front();
		this->mSum -= num;
		mQueue.pop();
		return num;
	}

	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		T maxNum = numeric_limits<T>::min();
		if (mQueue.empty())
		{
			return maxNum;
		}

		queue<T> tmpQu;
		int size = mQueue.size();
		for (int i = 0; i < size; i++)
		{
			T num = mQueue.front();
			maxNum = maxNum < num ? num : maxNum;
			mQueue.pop();
			tmpQu.push(num);
		}
		for (int i = 0; i < size; i++)
		{
			mQueue.push(tmpQu.front());
			tmpQu.pop();			
		}
		return maxNum;
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		T minNum = numeric_limits<T>::max();
		if (mQueue.empty())
		{
			return minNum;
		}

		queue<T> tmpQu;
		int size = mQueue.size();
		for (int i = 0; i < size; i++)
		{
			T num = mQueue.front();
			minNum = minNum > num ? num : minNum;
			mQueue.pop();
			tmpQu.push(num);
		}
		for (int i = 0; i < size; i++)
		{
			mQueue.push(tmpQu.front());
			tmpQu.pop();
		}
		return minNum;
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		return static_cast<double>(this->mSum) / static_cast<double>(mQueue.size());
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		//ºÐ»ê
		double avr = GetAverage();
		queue<T> tmpQu;
		int size = mQueue.size();
		T sum = T();
		for (int i = 0; i < size; i++)
		{
			T num = mQueue.front();
			mQueue.pop();
			tmpQu.push(num);

			sum += static_cast<T>(pow(static_cast<double>(num) - avr, 2));
		}
		double var = static_cast<double>(sum) / static_cast<double>(size);
		mQueue = tmpQu;
		/*for (int i = 0; i < size; i++)
		{
			T num = tmpQu.front();
			tmpQu.pop();
			mQueue.push(num);
		}*/
		return var;
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}
}

