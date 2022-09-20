#include "BinSrchTree.h"

CBinSrchTree::CBinSrchTree()
{
}

CBinSrchTree::~CBinSrchTree()
{
}

CBinaryNode* CBinSrchTree::SearchRecursive(char key)
{
	if (!m_Root)
		return nullptr;

	return m_Root->SearchRecursive(key);
}

CBinaryNode* CBinSrchTree::SearchIterative(char key)
{
	if (!m_Root)
		return nullptr;

	CBinaryNode* node = m_Root;

	while (node)
	{
		if (node->GetData() == key)
			return node;
		else
		{
			if (node->GetData() < key)
			{
				node = node->GetLeft();
			}
			else
			{
				node = node->GetRight();
			}
		}
	}

	return nullptr;
}

bool CBinSrchTree::Insert(CBinaryNode* node)
{
	CBinaryNode* curNode = m_Root;

	while (curNode)
	{
		if (curNode->GetData() == node->GetData())
			return false;
		else
		{
			if (node->GetData() < curNode->GetData())
			{
				curNode = curNode->GetLeft();

				if (!curNode)
				{
					curNode = node;
					break;
				}
			}
			else
			{
				curNode = curNode->GetRight();

				if (!curNode)
				{
					curNode = node;
					break;
				}
			}
		}
	}
}

bool CBinSrchTree::Remove(char data)
{
	CBinaryNode* parent = nullptr;
	CBinaryNode* curNode = m_Root;

	while (curNode)
	{
		if (curNode->GetData() == data)
		{
			// 삭제할 노드가 단말 노드인 경우
			if (curNode->IsLeaf())
			{
				// 삭제할 노드가 루트인 경우
				if (curNode == m_Root)
				{
					m_Root = nullptr;
				}
				else
				{
					if (parent->GetLeft() == curNode)
						parent->SetLeft(nullptr);
					else
						parent->SetRight(nullptr);
				}
			}
			// 삭제할 노드의 자식 노드가 하나일 경우
			else if (!curNode->GetLeft() || !curNode->GetRight())
			{
				// 삭제할 노드가 루트인 경우 삭제할 노드의 존재하는 자식을 루트로 한다.
				CBinaryNode* child = curNode->GetLeft() ? curNode->GetLeft() : curNode->GetRight();
				if (curNode == m_Root)
				{
					m_Root = child;
				}
				else
				{
					if (parent->GetLeft() == curNode)
						parent->SetLeft(child);
					else
						parent->SetRight(child);
				}
			}
			// 삭제할 노드의 양쪽 자식 노드가 존재하는 경우
			else
			{
				CBinaryNode* replace = curNode->GetRight();
				CBinaryNode* replaceParent = curNode;

				while (!replace->GetLeft())
				{
					replaceParent = replace;
					replace = replace->GetLeft();
				}

				// 승계될 노드가 삭제될 노드의 바로 오른쪽 자식이 아닐 경우
				// 승계될 노드의 부모는 승계될 노드의 오른쪽 자식을 왼쪽 자식으로 올린다.
				if (replace != curNode->GetRight())
					replaceParent->SetLeft(replace->GetRight());

				if (parent->GetLeft() == curNode)
					parent->SetLeft(replace);
				else
					parent->SetRight(replace);
			}

			delete curNode;
			curNode = nullptr;
		}
		else
		{
			parent = curNode;

			if (curNode->GetData() > data)
				curNode = curNode->GetLeft();
			else
				curNode = curNode->GetRight();
		}
	}
}
