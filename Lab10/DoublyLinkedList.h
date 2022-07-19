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
		}
		else
		{
			std::shared_ptr<Node<T>> CurNode = mHead;
			while (CurNode->Next != nullptr)
			{
				CurNode = CurNode->Next;
			}
			CurNode->Next = std::make_shared<Node<T>>(std::move(data), CurNode);
		}		
		mCurLength++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		std::shared_ptr<Node<T>> CurNode = mHead;
		for (unsigned int i = 1; i <= index; i++)
		{
			CurNode = CurNode->Next;
			if (i >= mCurLength)
			{
				break;
			}
		}

		if (CurNode == mHead)
		{
			auto tmp = std::make_shared<Node<T>>(std::move(data));
			tmp->Next = mHead;
			mHead->Previous = tmp;
			mHead = tmp;
		}
		else
		{
			auto tmp = std::make_shared<Node<T>>(std::move(data), CurNode->Previous.lock());
			tmp->Next = CurNode;
			CurNode->Previous.lock()->Next = tmp;
			tmp->Previous = CurNode->Previous;
			CurNode->Previous = tmp;

		}
		mCurLength++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> CurNode = mHead;
		while (CurNode != nullptr)
		{
			if (*(CurNode->Data) == data)
			{
				if (CurNode == mHead)
				{
					mHead = CurNode->Next;
					mHead->Previous.reset();
				}
				else
				{
					auto Prev = CurNode->Previous.lock();
					Prev->Next = CurNode->Next;
					CurNode->Next->Previous = CurNode->Previous;
				}
				mCurLength--;
				return true;
			}
			CurNode = CurNode->Next;
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> CurNode = mHead;
		while (CurNode != nullptr)
		{
			if (*(CurNode->Data) == data)
			{
				return true;
			}
			CurNode = CurNode->Next;
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

		std::shared_ptr<Node<T>> CurNode = mHead;
		for (unsigned int i = 1; i <= index; i++)
		{
			CurNode = CurNode->Next;
		}
		return CurNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mCurLength;
	}
}