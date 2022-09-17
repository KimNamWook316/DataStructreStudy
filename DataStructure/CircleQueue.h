#pragma once

#define MAX_SIZE_QUEUE 10

class CCircleQueue
{
public:
	CCircleQueue();

public:
	void Enqueue(int data);
	int Dequeue();
	int Front();
	bool IsEmpty();
	bool IsFull();
	virtual void Print();
	int Size();

protected:
	int m_Data[MAX_SIZE_QUEUE];
	int m_Front;
	int m_Rear;
};

