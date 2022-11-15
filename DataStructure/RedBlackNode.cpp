#include "RedBlackNode.h"

extern RedBlackNode NIL;

RedBlackNode::RedBlackNode(int data, Color color) :
	m_Data(data),
	m_Color((color))
{
}

RedBlackNode::~RedBlackNode()
{
}

void RedBlackNode::Clear()
{
	if (m_Left != &NIL)
		m_Left->Clear();

	if (m_Right != &NIL)
		m_Right->Clear();

	delete this;
}
