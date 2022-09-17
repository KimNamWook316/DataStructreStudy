#include <iostream>
#include "ThreadBTNode.h"

CThreadBTNode::CThreadBTNode(char data)	:
	m_Data(data)
{
}

CThreadBTNode::CThreadBTNode(char data, CThreadBTNode* left, CThreadBTNode* right, bool thread)	:
	m_Data(data),
	m_Left(left),
	m_Right(right),
	m_Thread(thread)
{
}

void CThreadBTNode::Print() const
{
	std::cout << " [" << m_Data << "]";
}
