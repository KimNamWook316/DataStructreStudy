#pragma once

#include "Node.h"

class CLinkedQueue
{
public:
	CLinkedQueue();
	~CLinkedQueue();

public:
	void Enqueue(int data);
	int Dequeue();
	int Front();
	bool IsEmpty();
	void Print();
	int Size();

private:
	CNode* m_Front;
	CNode* m_Rear;
};

