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
	printf("[%c] ", m_Data);
}

void CBinaryNode::InOrder()
{
	if (m_Left)
	{
		m_Left->InOrder();
	}

	printf("[%c] ", m_Data);

	if (m_Right)
	{
		m_Right->InOrder();
	}
}

void CBinaryNode::PreOrder()
{
	printf("[%c] ", m_Data);

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

	printf("[%c] ", m_Data);
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
