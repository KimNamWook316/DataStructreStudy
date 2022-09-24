#pragma once

#include "HeapNode.h"

constexpr int max_Element = 200;

class CMaxHeap
{
public:
	CMaxHeap();
	~CMaxHeap();

public:
	void Insert(int key);
	CHeapNode Remove();

public:
	bool IsEmpty();
	bool IsFull();
	void Display();

private:
	CHeapNode m_NodeArr[max_Element];
	int m_Size;
};
