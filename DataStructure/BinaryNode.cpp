#include <iostream>
#include "BinaryNode.h"

CBinaryNode::CBinaryNode()	:
	m_Left(nullptr),
	m_Right(nullptr),
	m_Data(-1)
{
}

CBinaryNode::CBinaryNode(char data) : 
	m_Left(nullptr),
	m_Right(nullptr)
{
	m_Data = data;
}

CBinaryNode::~CBinaryNode()
{
}

CBinaryNode* CBinaryNode::GetLeft()
{
	return m_Left;
}

CBinaryNode* CBinaryNode::GetRight()
{
	return m_Right;
}

void CBinaryNode::SetLeft(CBinaryNode* node)
{
	m_Left = node;
}

void CBinaryNode::SetRight(CBinaryNode* node)
{
	m_Right = node;
}

void CBinaryNode::Print()
{
	printf("[%d] ", m_Data);
}

void CBinaryNode::InOrder()
{
	if (m_Left)
	{
		m_Left->InOrder();
	}

	printf("[%d] ", m_Data);

	if (m_Right)
	{
		m_Right->InOrder();
	}
}

void CBinaryNode::PreOrder()
{
	printf("[%d] ", m_Data);

	if (m_Left)
	{
		m_Left->PreOrder();
	}
	if (m_Right)
	{
		m_Right->PreOrder();
	}
}

void CBinaryNode::PostOrder()
{
	if (m_Left)
	{
		m_Left->PostOrder();
	}
	if (m_Right)
	{
		m_Right->PostOrder();
	}

	printf("[%d] ", m_Data);
}

int CBinaryNode::GetCount()
{
	if (!m_Right && !m_Left)
	{
		return 1;
	}

	if (m_Right && !m_Left)
	{
		return 1 + m_Right->GetCount();
	}
	else if (!m_Right && m_Left)
	{
		return 1 + m_Left->GetCount();
	}
	else
	{
		return 1 + m_Left->GetCount() + m_Right->GetCount();
	}
}

int CBinaryNode::GetLeafCount()
{
	if (!m_Right && !m_Left)
	{
		return 1;
	}
	else
	{
		int leafCount = 0;
		if (m_Right)
		{
			leafCount += m_Right->GetLeafCount();
		}
		if (m_Left)
		{
			leafCount += m_Left->GetLeafCount();
		}

		return leafCount;
	}
}

int CBinaryNode::GetLevel()
{
	if (!m_Left && !m_Right)
	{
		return 1;
	}
	else
	{
		int lLevel = 0;
		int rLevel = 0;

		if (m_Left)
		{
			lLevel = m_Left->GetLevel();
		}
		if (m_Right)
		{
			rLevel = m_Right->GetLevel();
		}

		return (lLevel > rLevel) ? 1 + lLevel : 1 + rLevel;
	}
}

int CBinaryNode::IsLeaf()
{
	if (!m_Left && !m_Right)
		return true;
	else
		return false;
}

bool CBinaryNode::IsBalanced()
{
	bool balanced = true;

	int rLevel = 0;
	int lLevel = 0;

	if (m_Left)
		lLevel = m_Left->GetLevel();

	if (m_Right)
		rLevel = m_Right->GetLevel();

	// 레벨차가 2 이상으로 나는 경우
	if (abs(lLevel - rLevel) > 1)
		return false;

	// 자식 노드도 판별한다.
	if (m_Left)
		balanced = m_Left->IsBalanced();

	if (!balanced)
		return false;

	if (m_Right)
		balanced = m_Right->IsBalanced();

	return true;
}

int CBinaryNode::GetPathLength(int Level)
{
	std::cout << " Data : " << m_Data << " ";

	if (!m_Left && !m_Right)
		return 0;

	if (m_Left && m_Right)
		return ((Level * 2) + m_Left->GetPathLength(Level + 1) + m_Right->GetPathLength(Level + 1));

	if (m_Left)
		return Level + m_Left->GetPathLength(Level + 1);

	if (m_Right)
		return Level + m_Right->GetPathLength(Level + 1);
}

bool CBinaryNode::Swap()
{
	bool swap = true;

	if (m_Left)
		swap = m_Left->Swap();

	if (m_Right)
		swap = m_Right->Swap();

	CBinaryNode* temp = m_Left;
	m_Left = m_Right;
	m_Right = temp;

	return true;
}

void CBinaryNode::GetAllNode(std::list<CBinaryNode*>& outList)
{
	outList.push_back(this);

	if (m_Left)
		m_Left->GetAllNode(outList);

	if (m_Right)
		m_Right->GetAllNode(outList);
}

bool CBinaryNode::IsValid()
{
	if (!m_Left && !m_Right)
		return true;

	if (m_Left && m_Right)
	{
	}

	if (m_Left)
		return m_Left->IsValid();

	if (m_Right)
		return m_Right->IsValid();

	return false;
}

CBinaryNode* CBinaryNode::SearchRecursive(char key)
{
	if (key == m_Data)
		return this;

	if (key < m_Data)
	{
		if (!m_Left)
		{
			std::cout << "Key값이 " << static_cast<int>(key) << "인 노드 없음\n";
		}
		else
		{
			return m_Left->SearchRecursive(key);
		}
	}
	else
	{
		if (!m_Right)
		{
			std::cout << "Key값이 " << static_cast<int>(key) << "인 노드 없음\n";
		}
		else
		{
			return m_Right->SearchRecursive(key);
		}
	}
}
