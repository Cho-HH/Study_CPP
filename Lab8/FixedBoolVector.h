#pragma once
#include <algorithm>
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
		bool Remove(const bool bT);
		bool Get(size_t index) const;
		bool operator[](size_t index) const;
		int GetIndex(const bool t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mCurSize;
		size_t mArr;
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mCurSize(0)
		, mArr(0)
	{
	}

	template<size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& bOther)
		: mCurSize(bOther.mCurSize)
	{
		memcpy(mArr, bOther.mArr, N);
	}

	template<size_t N>
	FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector<bool, N>& bRhs)
	{
		mCurSize = bRhs.mCurSize;
		memcpy(mArr, bRhs.mArr, N);
	}
	
	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool bT)
	{
		if (mCurSize >= N)
		{
			return false;
		}

		if (bT)
		{
			mArr |= (1 << mCurSize++);
		}
		else
		{
			mArr &= ~(1 << mCurSize++);
		}
		return true;
	}

	template<size_t N>
	bool lab8::FixedVector<bool, N>::Remove(const bool t)
	{
		for (int i = 0; i < static_cast<int>(mCurSize); i++)
		{
			if (static_cast<bool>(mArr & (1 << i)) == t)
			{
				mArr &= ~(1 << i);
				mArr = (mArr >> std::max(i, 1) << std::max(i - 1, 0)) | (mArr << (32 - i - 1) >> (32 - i - 1));
				--mCurSize;
				return true;
			}
		}
		return false;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(size_t index) const
	{
		return mArr & (1 << index);
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](size_t index) const
	{
		return mArr & (1 << index);
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool bT) const
	{
		for (size_t i = 0; i < mCurSize; i++)
		{
			if (static_cast<bool>(mArr & (1 << i)) == bT)
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