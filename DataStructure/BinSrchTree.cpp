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

				while (!replace->GetLeft())
				{
					replaceParent = replace;
					replace = replace->GetLeft();
				}

				// �°�� ��尡 ������ ����� �ٷ� ������ �ڽ��� �ƴ� ���
				// �°�� ����� �θ�� �°�� ����� ������ �ڽ��� ���� �ڽ����� �ø���.
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
