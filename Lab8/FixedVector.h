#pragma once
#include <cstddef>

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<T, N>& other);
		FixedVector<T, N>& operator=(const FixedVector<T, N>& rhs);
		virtual ~FixedVector() = default;

		bool Add(const T& t);
		bool Remove(const T& t);
		T Get(size_t index) const;
		T& operator[](size_t index);
		int GetIndex(const T& t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mCurSize;
		T mArr[N];
	};

	
	template<typename T, size_t N>
	inline FixedVector<T, N>::FixedVector()
		: mCurSize(0)
		, mArr()
	{
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>::FixedVector(const FixedVector<T, N>& other)
		: mCurSize(other.mCurSize)
	{
		memcpy(mArr, other.mArr, N);
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector<T, N>& rhs)
	{
		mCurSize = rhs.mCurSize;
		memcpy(mArr, rhs.mArr, N);
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Add(const T& t)
	{
		if (mCurSize >= N)
		{
			return false;
		}

		mArr[mCurSize++] = t;
		return true;
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Remove(const T& t)
	{
		for (size_t i = 0; i < mCurSize; i++)
		{
			if (mArr[i] == t)
			{
				mArr[i] = T();
				for (size_t j = i; j < mCurSize - 1; j++)
				{
					mArr[j] = mArr[j + 1];
				}
				--mCurSize;
				return true;
			}
		}
		return false;
	}

	template<typename T, size_t N>
	inline T FixedVector<T, N>::Get(size_t index) const
	{
		return mArr[index];
	}

	template<typename T, size_t N>
	inline T& FixedVector<T, N>::operator[](size_t index)
	{
		return mArr[index];
	}

	template<typename T, size_t N>
	inline int FixedVector<T, N>::GetIndex(const T& t) const
	{
		for (size_t i = 0; i < mCurSize; i++)
		{
			if (mArr[i] == t)
			{
				return i;
			}
		}
		return -1;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetSize() const
	{
		return mCurSize;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}