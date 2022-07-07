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
		const T& Get(size_t index) const;
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
		for (int i = 0; i < mCurSize; i++)
		{
			memcpy(mArr[i], other.mArr[i], sizeof(other.mArr[i]));
		}
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector<T, N>& rhs)
	{
		mCurSize = rhs.mCurSize;
		for (int i = 0; i < mCurSize; i++)
		{
			memcpy(mArr, rhs.mArr[i], sizeof(rhs.mArr[i]));
		}
		return *this;
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
				size_t j;
				for (j = i; j < mCurSize - 1; j++)
				{
					mArr[j] = mArr[j + 1];
				}
				mArr[j] = T();
				--mCurSize;
				return true;
			}
		}
		return false;
	}

	template<typename T, size_t N>
	inline const T& FixedVector<T, N>::Get(size_t index) const
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


	template<typename T, size_t N>
	class FixedVector<T*, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<T*, N>& other);
		FixedVector<T*, N>& operator=(const FixedVector<T*, N>& rhs);
		virtual ~FixedVector();

		bool Add(T*& t);
		bool Remove(const T*& t);
		const T*& Get(size_t index) const;
		T*& operator[](size_t index);
		int GetIndex(const T*& t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mCurSize;
		T* mArr[N];
	};

	template<typename T, size_t N>
	inline FixedVector<T*, N>::FixedVector()
		: mCurSize(0)
	{
		for (size_t i = 0; i < N; i++)
		{
			mArr[i] = new T();
		}
	}

	template<typename T, size_t N>
	inline FixedVector<T*, N>::~FixedVector()
	{
		for (size_t i = 0; i < N; i++)
		{
			delete mArr[i];
		}
	}

	template<typename T, size_t N>
	inline FixedVector<T*, N>::FixedVector(const FixedVector<T*, N>& other)
		: mCurSize(other.mCurSize)
	{
		for (size_t i = 0; i < N; i++)
		{
			mArr[i] = new T();
		}
		
		for (size_t i = 0; i < mCurSize; i++)
		{
			memcpy(mArr[i], other.mArr[i], sizeof(other.mArr[i]));
		}
	}

	template<typename T, size_t N>
	inline FixedVector<T*, N>& FixedVector<T*, N>::operator=(const FixedVector<T*, N>& rhs)
	{
		for (size_t i = 0; i < mCurSize; i++)
		{
			*mArr[i] = T();
		}
		mCurSize = rhs.mCurSize;
		for (size_t i = 0; i < mCurSize; i++)
		{
			memcpy(mArr[i], rhs.mArr[i], sizeof(rhs.mArr[i]));
		}
		return *this;
	}

	template<typename T, size_t N>
	inline bool FixedVector<T*, N>::Add(T*& t)
	{
		if (mCurSize >= N)
		{
			return false;
		}
		mArr[mCurSize++] = t;
		return true;
	}

	template<typename T, size_t N>
	inline bool FixedVector<T*, N>::Remove(const T*& t)
	{
		for (size_t i = 0; i < mCurSize; i++)
		{
			if (mArr[i] == t)
			{
				delete mArr[i];
				size_t j;
				for (j = i; j < mCurSize - 1; j++)
				{
					mArr[j] = mArr[j + 1];
				}
				mArr[j] = new T();
				--mCurSize;
				return true;
			}
		}
		return false;
	}

	template<typename T, size_t N>
	inline const T*& FixedVector<T*, N>::Get(size_t index) const
	{
		return mArr[index];
	}

	template<typename T, size_t N>
	inline T*& FixedVector<T*, N>::operator[](size_t index)
	{
		return mArr[index];
	}

	template<typename T, size_t N>
	inline int FixedVector<T*, N>::GetIndex(const T*& t) const
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
	inline size_t FixedVector<T*, N>::GetSize() const
	{
		return mCurSize;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T*, N>::GetCapacity() const
	{
		return N;
	}
}