#include <iostream>
#include "HeapNode.h"

CHeapNode::CHeapNode()	:
	m_Key(-1)
{
}

CHeapNode::CHeapNode(int key)	:
	m_Key(key)
{
}

CHeapNode::~CHeapNode()
{
}

void CHeapNode::Display()
{
	std::cout << "[" << m_Key << "]" << " ";
}
