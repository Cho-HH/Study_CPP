#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);

		Storage(const Storage& other);
		Storage<T>& operator=(const Storage& other);

		Storage(Storage&& other);
		Storage<T>& operator=(Storage&& other);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mData;
		unsigned int mSize;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mSize(length)
	{
		mData = std::make_unique<T[]>(length);
		//내부에서 T()로 초기화??
		//memset(mData.get(), T(), sizeof(length));
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mSize(length)
	{
		mData = std::make_unique<T[]>(length);
		for (unsigned int i = 0; i < length; i++)
		{
			mData[i] = initialValue;
		}
	}

	template<typename T>
	inline Storage<T>::Storage(const Storage& other)
	{
		mSize = other.mSize;
		mData = std::make_unique<T[]>(other.mSize);
		for (unsigned int i = 0; i < other.mSize; i++)
		{
			mData[i] = other.mData[i];
		}
	}

	template<typename T>
	inline Storage<T>& Storage<T>::operator=(const Storage& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mData = std::make_unique<T[]>(other.mSize);
		//mData.reset(std::make_unique<T[]>(other.mSize));
		for (unsigned int i = 0; i < other.mSize; i++)
		{
			mData[i] = other.mData[i];
		}
		mSize = other.mSize;
		return *this;
	}


	template<typename T>
	inline Storage<T>::Storage(Storage&& other)
		: mSize(other.mSize)
	{
		mData = std::move(other.mData);
		other.mSize = 0;
	}

	template<typename T>
	inline Storage<T>& Storage<T>::operator=(Storage&& other)
	{
		if (this == &other)
		{
			return *this;
		}
		
		mData = std::move(other.mData);
		mSize = other.mSize;
		other.mSize = 0;
		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (mSize <= index)
		{
			return false;
		}

		mData[index] = data;
		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mData);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mSize;
	}
}