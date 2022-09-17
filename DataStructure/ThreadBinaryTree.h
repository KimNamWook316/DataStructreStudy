#pragma once

#include "ThreadBTNode.h"

class CThreadBinaryTree
{
public:
	CThreadBinaryTree();

public:
	void InOrder();

public:
	void SetRoot(CThreadBTNode* root)
	{
		m_Root = root;
	}

private:
	CThreadBTNode* findSuccessor(CThreadBTNode* node);

private:
	CThreadBTNode* m_Root;
};

