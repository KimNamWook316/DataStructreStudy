#pragma once

#include "Node.h"

class CLinkedStack
{
public:
	CLinkedStack();
	~CLinkedStack();

public:
	void Push(int Data);
	void Pop();
	int Top();
	int GetSize() const;
	bool IsEmpty() const;
	void Print() const;

private:
	CNode* m_Top;
};

