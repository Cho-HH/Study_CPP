#pragma once

#include <memory>
#include <vector>
//#include "TreeNode.h"

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mRootNode;
		void InsertRecursive(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T> data);
		bool SearchRecursive(const std::shared_ptr<TreeNode<T>>& node, const T& data);
		bool DeleteRecursive(const std::shared_ptr<TreeNode<T>>& node, const T& data);
		static void TraverseInOrderRecursive(std::vector<T>& vec, const std::shared_ptr<TreeNode<T>>& node);
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRootNode == nullptr)
		{
			mRootNode = std::make_shared<TreeNode<T>>(std::move(data));
			return;
		}
		InsertRecursive(mRootNode, std::move(data));
	}

	template<typename T>
	void BinarySearchTree<T>::InsertRecursive(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T> data)
	{
		if (*data < *(node->Data))
		{
			if (node->Left == nullptr)
			{
				node->Left = std::make_shared<TreeNode<T>>(node, std::move(data));
				return;
			}
			InsertRecursive(node->Left, std::move(data));
		}
		else
		{
			if (node->Right == nullptr)
			{
				node->Right = std::make_shared<TreeNode<T>>(node, std::move(data));
				return;
			}
			InsertRecursive(node->Right, std::move(data));
		}
	}
	
	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRootNode;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		return SearchRecursive(mRootNode, data);
	}

	template<typename T>
	bool BinarySearchTree<T>::SearchRecursive(const std::shared_ptr<TreeNode<T>>& node, const T& data)
	{
		if (node == nullptr)
		{
			return false;
		}

 		if (data == *(node->Data))
		{
			return true;
		}

		if (data < *(node->Data))
		{
			return SearchRecursive(node->Left, data);
		}
		else
		{
			return SearchRecursive(node->Right, data);
		}
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return DeleteRecursive(mRootNode, data);
	}

	template<typename T>
	inline bool BinarySearchTree<T>::DeleteRecursive(const std::shared_ptr<TreeNode<T>>& node, const T& data)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (data == *(node->Data))
		{
			std::shared_ptr<TreeNode<T>> parent = node->Parent.lock();

			if (mRootNode == node)
				//�����Ϸ��� ��尡 ��Ʈ���
			{
				if (node->Right == nullptr && node->Left == nullptr)
				{
					mRootNode = nullptr;
				}
				else if (node->Right == nullptr && node->Left != nullptr)
				{

					mRootNode = node->Left;
					mRootNode->Parent.reset();
				}
				else if (node->Right != nullptr && node->Left == nullptr)
				{
					mRootNode = node->Right;
					mRootNode->Parent.reset();
				}
				else
				{
					std::shared_ptr<TreeNode<T>> tmpNode = node;
					while (tmpNode->Left != nullptr)
					{
						tmpNode = tmpNode->Left;
					}
					tmpNode = tmpNode->Right != nullptr ? tmpNode->Right : tmpNode;

					//��ü����� �θ��� �ڽĲ���
					parent = tmpNode->Parent.lock();
					if (tmpNode == parent->Left)
					{
						parent->Left = nullptr;
					}
					else
					{
						parent->Right = nullptr;
					}

					mRootNode->Left->Parent = tmpNode;
					mRootNode->Right->Parent = tmpNode;
					tmpNode->Parent.reset();
					tmpNode->Left = mRootNode->Left;
					tmpNode->Right = mRootNode->Right;
					mRootNode = tmpNode;
				}
			}	
			else if (node->Left == nullptr && node->Right == nullptr)
				//�����Ϸ��� ��尡 �������
			{				
				if (node == parent->Left)
				{
					parent->Left = nullptr;
				}
				else
				{
					parent->Right = nullptr;
				}
			}
			else if (node->Left == nullptr && node->Right != nullptr)
				//�����Ϸ��� ����� Left�� nullptr�� ���
			{
				if (node == parent->Left)
				{
					node->Right->Parent = parent;
					parent->Left = node->Right;
				}
				else
				{
					node->Right->Parent = parent;
					parent->Right = node->Right;
				}
			}
			else if (node->Left != nullptr && node->Right == nullptr)
				//�����Ϸ��� ����� Right�� nullptr�� ���
			{
				if (node == parent->Left)
				{
					node->Left->Parent = parent;
					parent->Left = node->Left;					
				}
				else
				{
					node->Left->Parent = parent;
					parent->Right = node->Left;					
				}
			}
			else
				//�����Ϸ��� ����� �ڽ��� �� �� nullptr�� �ƴ� ���
			{
				std::shared_ptr<TreeNode<T>> deleteNode = node;
				std::shared_ptr<TreeNode<T>> tmpNode = node;
				while (tmpNode->Left != nullptr)
				{
					tmpNode = tmpNode->Left;
				}
				tmpNode = tmpNode->Right != nullptr ? tmpNode->Right : tmpNode;

				//��ü����� �θ��� �ڽĲ���
				parent = tmpNode->Parent.lock();
				if (tmpNode == parent->Left)
				{
					parent->Left = nullptr;
				}
				else
				{
					parent->Right = nullptr;
				}

				//��ü����� �θ� ��������� �θ�� ����
				parent = deleteNode->Parent.lock();
				if (deleteNode == parent->Left)
				{
					tmpNode->Parent = parent;
					parent->Left = tmpNode;
				}
				else
				{
					tmpNode->Parent = parent;
					parent->Right = tmpNode;
				}

				deleteNode->Left->Parent = tmpNode;
				deleteNode->Right->Parent = tmpNode;
				//��ü����� ���ʿ� ��������� ���� ����
				tmpNode->Left = deleteNode->Left;
				tmpNode->Right = deleteNode->Right;
			}
			
			return true;
		}
		 
		if (data < *(node->Data))
		{
			return DeleteRecursive(node->Left, data);
		}
		else
		{
			return DeleteRecursive(node->Right, data);
		}

		return true;
	}

	
	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		TraverseInOrderRecursive(v, startNode);
		return v;
	}

	template<typename T>
	inline void BinarySearchTree<T>::TraverseInOrderRecursive(std::vector<T>& vec, const std::shared_ptr<TreeNode<T>>& node)
	{
		if (node == nullptr)
		{
			return;
		}

		TraverseInOrderRecursive(vec, node->Left);
		vec.push_back(*(node->Data));
		TraverseInOrderRecursive(vec, node->Right);
	}
	
}