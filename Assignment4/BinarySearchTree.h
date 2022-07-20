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
		void insertRecursive(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T> data);
		bool searchRecursive(const std::shared_ptr<TreeNode<T>>& node, const T& data);
		bool deleteRecursive(const std::shared_ptr<TreeNode<T>> node, const T& data);
		static void traverseInOrderRecursive(std::vector<T>& vec, const std::shared_ptr<TreeNode<T>>& node);
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
	void BinarySearchTree<T>::insertRecursive(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T> data)
	{
		if (*data <= *(node->Data))
		{
			if (node->Left == nullptr)
			{
				node->Left = std::make_shared<TreeNode<T>>(node, std::move(data));
				return;
			}
			insertRecursive(node->Left, std::move(data));
		}
		else
		{
			if (node->Right == nullptr)
			{
				node->Right = std::make_shared<TreeNode<T>>(node, std::move(data));
				return;
			}
			insertRecursive(node->Right, std::move(data));
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
	bool BinarySearchTree<T>::searchRecursive(const std::shared_ptr<TreeNode<T>>& node, const T& data)
	{
		if (node == nullptr)
		{
			return false;
		}

 		if (data == * (node->Data))
		{
			return true;
		}

		if (data < *(node->Data))
		{
			return searchRecursive(node->Left, data);
		}
		else
		{
			return searchRecursive(node->Right, data);
		}
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return DeleteRecursive(mRootNode, data);
	}

	template<typename T>
	inline bool BinarySearchTree<T>::deleteRecursive(const std::shared_ptr<TreeNode<T>> node, const T& data)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (data == *(node->Data))
		{		
			if (mRootNode == node)
				//삭제하려는 노드가 루트노드
			{
				if (node->Right == nullptr && node->Left == nullptr)
					//노드가 루트노드만 있을 때
				{
					mRootNode = nullptr;
				}
				else if (node->Right == nullptr && node->Left != nullptr)
					//노드가 왼쪽만 있을 때
				{

					mRootNode = node->Left;
				}
				else if (node->Right != nullptr && node->Left == nullptr)
					//노드가 오른쪽만 있을 때
				{
					mRootNode = node->Right;
				}
				else
					//노드가 양쪽 다 있을 때
				{
					std::shared_ptr<TreeNode<T>> tmpNode = node->Right;
					while (tmpNode->Left != nullptr)
					{
						tmpNode = tmpNode->Left;
					}

					if (tmpNode == mRootNode->Right)
						//대체노드가 루트노드의 바로 오른쪽 자식
					{
						tmpNode->Left = mRootNode->Left;
						mRootNode = tmpNode;
					}
					else
					{
						auto tmpParent = tmpNode->Parent.lock();
						tmpParent->Left = tmpNode->Right;
						if (tmpParent->Left != nullptr)
						{
							tmpParent->Left->Parent = tmpParent;
						}
						tmpNode->Left = mRootNode->Left;
						tmpNode->Right = mRootNode->Right;
						tmpNode->Right->Parent = tmpNode;
						tmpNode->Left->Parent = tmpNode;
						tmpNode->Parent.reset();
						mRootNode = tmpNode;
					}
				}
			}	
			else if (node->Left == nullptr && node->Right == nullptr)
				//삭제하려는 노드가 리프노드
			{				
				std::shared_ptr<TreeNode<T>> parent = node->Parent.lock();
				if (node == parent->Left)
				{
					parent->Left = nullptr;
				}
				else
				{
					parent->Right = nullptr;
				}
			}
			else
				//루트도 아니고 리프도 아님
			{
				std::shared_ptr<TreeNode<T>> parent = node->Parent.lock();
				if (node->Left == nullptr && node->Right != nullptr)
					//삭제하려는 노드의 Left가 nullptr인 경우
				{
					if (node == parent->Left)
					{
						parent->Left = node->Right;
						node->Right->Parent = parent;
					}
					else
					{
						parent->Right = node->Right;
						node->Right->Parent = parent;
					}
				}
				else if (node->Left != nullptr && node->Right == nullptr)
					//삭제하려는 노드의 Right가 nullptr인 경우
				{
					if (node == parent->Left)
					{
						parent->Left = node->Left;
						parent->Left->Parent = parent;
						//node->Left->Parent = parent;
					}
					else
					{
						parent->Right = node->Left;
						parent->Right->Parent = parent;
						//node->Left->Parent = parent;
					}
				}
				else
					//삭제하려는 노드의 자식이 둘 다 nullptr이 아닌 경우
				{
					//std::shared_ptr<TreeNode<T>> deleteNode = node;
					std::shared_ptr<TreeNode<T>> tmpNode = node->Right;
					while (tmpNode->Left != nullptr)
					{
						tmpNode = tmpNode->Left;
					}
										
					if (tmpNode == node->Right)
						//대체노드가 삭제노드의 바로 오른쪽 자식
					{
						auto parent = node->Parent.lock();
						if (node == parent->Left)
						{
							parent->Left = tmpNode;
						}
						else
						{
							parent->Right = tmpNode;
						}
						tmpNode->Left = node->Left;
						tmpNode->Parent = parent;
						tmpNode->Left->Parent = tmpNode;
					}
					else
					{
						auto deleteParent = node->Parent.lock();
						//대체노드의 부모의 자식끊기
						tmpNode->Parent.lock()->Left = nullptr;

						//대체노드의 부모를 삭제노드의 부모와 연결
						if (node == deleteParent->Left)
						{
							deleteParent->Left = tmpNode;
							tmpNode->Parent = deleteParent;
						}
						else
						{
							deleteParent->Right = tmpNode;
							tmpNode->Parent = deleteParent;
						}
						//대체노드의 양쪽에 삭제노드의 양쪽 연결
						tmpNode->Left = node->Left;
						tmpNode->Right = node->Right;
						node->Left->Parent = tmpNode;
						node->Right->Parent = tmpNode;
					}				
				}
			}
			
			return true;
		}
		 
		if (data < *(node->Data))
		{
			return deleteRecursive(node->Left, data);
		}
		else
		{
			return deleteRecursive(node->Right, data);
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
	inline void BinarySearchTree<T>::traverseInOrderRecursive(std::vector<T>& vec, const std::shared_ptr<TreeNode<T>>& node)
	{
		if (node == nullptr)
		{
			return;
		}

		traverseInOrderRecursive(vec, node->Left);
		vec.push_back(*(node->Data));
		traverseInOrderRecursive(vec, node->Right);
	}
	
}