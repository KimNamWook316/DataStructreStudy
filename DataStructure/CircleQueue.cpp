#include <iostream>
#include <memory>
#include "CircleQueue.h"

CCircleQueue::CCircleQueue():
	m_Front(0),
	m_Rear(0)
{
	memset(m_Data, 0, sizeof(m_Data));
}

void CCircleQueue::Enqueue(int data)
{
	if (IsFull())
	{
		return;
	}

	m_Rear = (m_Rear + 1) % MAX_SIZE_QUEUE;
	m_Data[m_Rear] = data;
}

int CCircleQueue::Dequeue()
{
	if (IsEmpty())
	{
		return -1;
	}

	m_Front = (m_Front + 1) % MAX_SIZE_QUEUE;

	int data = m_Data[m_Front];
	m_Data[m_Front] = 0;

	return data;
}

int CCircleQueue::Front()
{
	if (IsEmpty())
	{
		return - 1;
	}

	int Front = (m_Front + 1) % MAX_SIZE_QUEUE;

	return m_Data[Front];
}

bool CCircleQueue::IsEmpty()
{
	return m_Front == m_Rear;
}

bool CCircleQueue::IsFull()
{
	return (m_Front == ((m_Rear + 1) % MAX_SIZE_QUEUE));
}

void CCircleQueue::Print()
{
	printf("=== Circle Queue Data ===\n");

	int Front = m_Front;
	int Rear = m_Rear;

	while (Front != Rear)
	{
		Front = (Front + 1) % MAX_SIZE_QUEUE;
		printf("Queue Data : %d\n", m_Data[Front]);
	}

	printf("=========================\n");
}

int CCircleQueue::Size()
{
	int Front = m_Front;
	int Rear = m_Rear;
	int Size = 0;

	while (Front != Rear)
	{
		++Size;
		Front = (Front + 1) % MAX_SIZE_QUEUE;
	}

	return Size;
}
