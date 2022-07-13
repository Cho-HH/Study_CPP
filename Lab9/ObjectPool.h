#pragma once
#include <memory>
#include <queue>

namespace lab9
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool() = delete;
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool&) = delete;
		ObjectPool& operator=(const ObjectPool&) = delete;
		virtual ~ObjectPool() = default;

		T* Get();
		void Return(T*);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();
	private:
		size_t mMaxPoolSize;
		std::queue<std::unique_ptr<T>> mPool;
	};

	template<typename T>
	inline ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
	}

	template<typename T>
	inline T* ObjectPool<T>::Get()
	{
		if (mPool.empty())
		{
			std::unique_ptr<T> obj = std::make_unique<T>();
			mPool.push(std::move(obj));
		}
		std::unique_ptr<T> tmp = std::move(mPool.front());
		mPool.pop();
		return tmp.release();
	}

	template<typename T>
	inline void ObjectPool<T>::Return(T* obj)
	{
		if (mPool.size() >= mMaxPoolSize)
		{
			delete obj;
			return;
		}
		mPool.push(std::unique_ptr<T>(obj));
	}

	template<typename T>
	inline size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mPool.size();
	}

	template<typename T>
	inline size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}

}
