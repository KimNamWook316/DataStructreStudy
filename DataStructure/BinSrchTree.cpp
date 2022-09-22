#include <iostream>
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
	{
		std::cout << "Key���� " << static_cast<int>(key) << "�� ��� ����\n";
		return nullptr;
	}

	CBinaryNode* node = m_Root;

	while (node)
	{
		if (node->GetData() == key)
		{
			std::cout << "Key���� " << static_cast<int>(key) << "�� ��� : " << &node << '\n';
			return node;
		}
		else
		{
			if (node->GetData() > key)
			{
				node = node->GetLeft();
			}
			else
			{
				node = node->GetRight();
			}
		}
	}

		std::cout << "Key���� " << static_cast<int>(key) << "�� ��� ����\n";
	return nullptr;
}

bool CBinSrchTree::Insert(CBinaryNode* node)
{
	if (!m_Root)
	{
		m_Root = node;
		return true;
	}

	CBinaryNode* curNode = m_Root;

	while (curNode)
	{
		if (curNode->GetData() == node->GetData())
			return false;
		else
		{
			if (node->GetData() < curNode->GetData())
			{
				if (!curNode->GetLeft())
				{
					curNode->SetLeft(node);
					break;
				}
				else
				{
					curNode = curNode->GetLeft();
				}
			}
			else
			{
				if (!curNode->GetRight())
				{
					curNode->SetRight(node);
					break;
				}
				else 
				{
					curNode = curNode->GetRight();
				}
			}
		}
	}

	return true;
}

bool CBinSrchTree::Remove(char data)
{
	CBinaryNode* parent = nullptr;
	CBinaryNode* curNode = m_Root;

	while (curNode)
	{
		if (curNode->GetData() == data)
		{
			// ������ ��尡 �ܸ� ����� ���
			if (curNode->IsLeaf())
			{
				// ������ ��尡 ��Ʈ�� ���
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
			// ������ ����� �ڽ� ��尡 �ϳ��� ���
			else if (!curNode->GetLeft() || !curNode->GetRight())
			{
				// ������ ��尡 ��Ʈ�� ��� ������ ����� �����ϴ� �ڽ��� ��Ʈ�� �Ѵ�.
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
			// ������ ����� ���� �ڽ� ��尡 �����ϴ� ���
			else
			{
				CBinaryNode* replace = curNode->GetRight();
				CBinaryNode* replaceParent = curNode;

				while (replace->GetLeft())
				{
					replaceParent = replace;
					replace = replace->GetLeft();
				}

				// �°�� ��尡 ������ ����� �ٷ� ������ �ڽ��� �ƴ� ���
				// �°�� ����� �θ�� �°�� ����� ������ �ڽ��� ���� �ڽ����� �ø���.
				if (replace != curNode->GetRight())
					replaceParent->SetLeft(replace->GetRight());

				if (!parent)
					m_Root = replace;
				else if (parent->GetLeft() == curNode)
					parent->SetLeft(replace);
				else
					parent->SetRight(replace);

				if (curNode->GetLeft() != replace)
					replace->SetLeft(curNode->GetLeft());
				if (curNode->GetRight() != replace)
					replace->SetRight(curNode->GetRight());
			}

			delete curNode;
			curNode = nullptr;

			return true;
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

	return false;
}
