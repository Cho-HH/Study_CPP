#pragma once
#include <cstddef>

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<bool, N>& other);
		FixedVector<bool, N>& operator=(const FixedVector<bool, N>& rhs);
		virtual ~FixedVector() = default;

		bool Add(const bool t);
		bool Remove(const bool t);
		bool Get(size_t index) const;
		bool operator[](size_t index) const;
		int GetIndex(const bool t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mCurSize;
		size_t mCurArr;
		size_t mArr[N / 32 + 1];
		size_t mTmp;
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mCurSize(0)
		, mArr{}
		, mCurArr(0)
		, mTmp(0)
	{
	}

	template<size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& other)
		: mCurSize(other.mCurSize)
		, mCurArr(0)
		, mTmp(0)
	{
		for (int i = 0; i < mCurArr; i++)
		{
			mArr[i] = other.mArr;
		}
	}

	template<size_t N>
	FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector<bool, N>& rhs)
	{
		mArr = { 0, };
		mCurSize = rhs.mCurSize;
		mCurArr = rhs.mCurArr;
		mTmp = rhs.mTmp;
		for (int i = 0; i < mCurArr; i++)
		{
			mArr[i] = rhs.mArr;
		}
		return *this;
	}
	
	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool t)
	{
		if (mCurSize >= N)
		{
			return false;
		}

		if (t)
		{
			mArr[mCurArr] |= (1 << mCurSize++);
		}
		else
		{
			mArr[mCurArr] &= ~(1 << mCurSize++);
		}
		if (++mTmp >= 32)
		{
			mTmp = 0;
			mCurArr++;
		}
		return true;
	}

	template<size_t N>
	bool lab8::FixedVector<bool, N>::Remove(const bool t)
	{
		for (int i = 0; i < static_cast<int>(mCurSize); i++)
		{
			if (static_cast<bool>(mArr[i / 32] & (1 << (i % 32))) == t)
			{
				int j;
				for (j = i; j < static_cast<int>(mCurSize) - 1; j++)
				{
					if (static_cast<bool>(mArr[(j + 1) / 32] & (1 << ((j + 1) % 32))))
					{
						mArr[j / 32] |= (1 << (j % 32));
					}
					else
					{
						mArr[j / 32] &= ~(1 << (j % 32));
					}
				}
				mArr[j / 32] &= ~(1 << (j % 32));
				--mCurSize;
				return true;
			}
		}
		return false;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(size_t index) const
	{
		return static_cast<bool>(mArr[index / 32] & (1 << index % 32));
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](size_t index) const
	{
		return static_cast<bool>(mArr[index / 32] & (1 << index % 32));
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool t) const
	{
		for (size_t i = 0; i < mCurSize; i++)
		{
			if (static_cast<bool>(mArr[i / 32] & (1 << (i % 32))) == t)
			{
				return i;
			}
		}
		return -1;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mCurSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}