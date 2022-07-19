#pragma once

#include <memory>
#include "Node.h"

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		unsigned int mCurLength;
		std::shared_ptr<Node<T>> mHead;
		std::shared_ptr<Node<T>> mTail;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mCurLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mHead == nullptr)
		{
			mHead = std::make_shared<Node<T>>(std::move(data));
			mTail = mHead;
		}
		else
		{
			auto node = std::make_shared<Node<T>>(std::move(data), mTail);
			mTail->Next = node;
			mTail = node;
			/*std::shared_ptr<Node<T>> curNode = mHead;
			while (curNode->Next != nullptr)
			{
				curNode = curNode->Next;
			}
			curNode->Next = std::make_shared<Node<T>>(std::move(data), curNode);*/
		}		
		mCurLength++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index >= mCurLength)
		{
			auto node = std::make_shared<Node<T>>(std::move(data), mTail);
			mTail->Next = node;
			mTail = node;
		}
		else
		{
			std::shared_ptr<Node<T>> curNode = mHead;			
			for (unsigned int i = 1; i <= index; i++)
			{
				curNode = curNode->Next;
			}

			if (curNode == mHead)
			{
				auto tmp = std::make_shared<Node<T>>(std::move(data));
				tmp->Next = mHead;
				mHead->Previous = tmp;
				mHead = tmp;
			}
			else
			{
				auto tmp = std::make_shared<Node<T>>(std::move(data), curNode->Previous.lock());
				tmp->Next = curNode;
				curNode->Previous.lock()->Next = tmp;
				tmp->Previous = curNode->Previous;
				curNode->Previous = tmp;

			}
		}		
		mCurLength++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> curNode = mHead;
		while (curNode != nullptr)
		{
			if (*(curNode->Data) == data)
			{
				if (curNode == mHead)
				{
					mHead = curNode->Next;
					//mHead->Previous.reset();
					if (mHead == nullptr)
					{
						mTail = nullptr;
					}
				}
				else if (curNode == mTail)
				{
					mTail = mTail->Previous.lock();
					mTail->Next = nullptr;
				}
				else
				{
					auto Prev = curNode->Previous.lock();
					Prev->Next = curNode->Next;
					curNode->Next->Previous = curNode->Previous;					
				}
				mCurLength--;
				return true;
			}
			curNode = curNode->Next;
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> curNode = mHead;
		while (curNode != nullptr)
		{
			if (*(curNode->Data) == data)
			{
				return true;
			}
			curNode = curNode->Next;
		}
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mCurLength)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> curNode = mHead;
		for (unsigned int i = 1; i <= index; i++)
		{
			curNode = curNode->Next;
		}
		return curNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mCurLength;
	}
}