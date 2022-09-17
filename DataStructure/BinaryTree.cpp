#include <cstdio>
#include <queue>
#include "BinaryTree.h"

CBinaryTree::CBinaryTree()	:
	m_Root(nullptr)
{
}

CBinaryTree::~CBinaryTree()
{
}

void CBinaryTree::SetRoot(CBinaryNode* root)
{
	m_Root = root;
}

bool CBinaryTree::IsEmpty()
{
	return m_Root == nullptr;
}

int CBinaryTree::GetCount()
{
	if (!m_Root)
	{
		return 0;
	}

	return m_Root->GetCount();
}

int CBinaryTree::GetHeight()
{
	int height = 0;
	if (m_Root)
	{
		height = m_Root->GetLevel();
	}
	return height;
}

int CBinaryTree::GetLeafCount()
{
	int leafCount = 0;
	if (m_Root)
	{
		leafCount = m_Root->GetLeafCount();
	}

	return leafCount;
}

void CBinaryTree::LevelOrder()
{
	printf("LevelOrder\n");
	if (m_Root)
	{
		std::queue<CBinaryNode*> levelQueue;
		levelQueue.push(m_Root);

		while (!levelQueue.empty())
		{
			CBinaryNode* top = levelQueue.front();
			top->Print();

			if (top->GetLeft())
			{
				levelQueue.push(top->GetLeft());
			}
			if (top->GetRight())
			{
				levelQueue.push(top->GetRight());
			}

			levelQueue.pop();
		}
	}
	printf("===========================\n");
}

void CBinaryTree::InOrder()
{
	printf("InOrder\n");
	if (m_Root)
	{
		m_Root->InOrder();
	}
	printf("===========================\n");
}

void CBinaryTree::PreOrder()
{
	printf("PreOrder\n");
	if (m_Root)
	{
		m_Root->PreOrder();
	}
	printf("===========================\n");
}

void CBinaryTree::PostOrder()
{
	printf("PostOrder\n");
	if (m_Root)
	{
		m_Root->PostOrder();
	}
	printf("===========================\n");
}

bool CBinaryTree::IsFull()
{
	std::queue<CBinaryNode*> bQueue;
	bQueue.push(m_Root);

	while (!bQueue.empty())
	{
		bool meetNotFull = false;
		CBinaryNode* node = bQueue.front();

		// full node��� ��� Ž���Ѵ�.
		if (node->GetLeft() && node->GetRight())
		{
			bQueue.push(node->GetLeft());
			bQueue.push(node->GetRight());
			bQueue.pop();
		}
		else
		{
			// Full Node�� �ƴ� ��带 ������ ���, ��� ��尡 �ܸ� ��忩�� �Ѵ�.
			if (meetNotFull)
			{
				if (!node->IsLeaf())
					return false;
			}
			else
			{
				// �����ʸ� �ִ� ��尡 �����ϸ� ���� ����Ʈ���� �ƴϴ�
				if (!node->GetLeft() && node->GetRight())
					return false;

				// Full Node�� �ƴ� Node�� ó�� ����
				meetNotFull = true;

				if (node->GetLeft())
					bQueue.push(node->GetLeft());

				bQueue.pop();
			}
		}
	}

	return true;
}

int CBinaryTree::GetLevel()
{
	return 0;
}
