#include "Node.h"
#include <iostream>

CNode::CNode(int Data)	:
	m_Data(Data),
	m_Link(nullptr)
{
}

int CNode::GetData() const
{
	return m_Data;
}

void CNode::SetLink(CNode* Node)
{
	m_Link = Node;
}

CNode* CNode::GetLink()
{
	return m_Link;
}

void CNode::Print() const
{
	printf("Data : %d\n", m_Data);
}
