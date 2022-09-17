#include <iostream>
#include "CircleDeque.h"

CCircleDeque::CCircleDeque()
{
}

void CCircleDeque::AddFront(int data)
{
    if (IsFull())
    {
        return;
    }

    m_Data[m_Front] = data;
    m_Front = (m_Front == 0) ? MAX_SIZE_QUEUE - 1 : m_Front - 1;
}

int CCircleDeque::DeleteFront()
{
    return Dequeue();
}

int CCircleDeque::GetFront()
{
    return Front();
}

void CCircleDeque::AddRear(int data)
{
    Enqueue(data);
}

int CCircleDeque::DeleteRear()
{
    if (IsEmpty())
    {
        return -1;
    }

    int data = m_Data[m_Rear];

    m_Rear = (m_Rear == 0) ? MAX_SIZE_QUEUE - 1 : m_Rear - 1;

    return data;
}

int CCircleDeque::GetRear()
{
    if (IsEmpty())
    {
        return -1;
    }

    return m_Data[m_Rear];
}

void CCircleDeque::Print()
{
	printf("=== Circle Deque Data ===\n");

	int Front = m_Front;
	int Rear = m_Rear;

	while (Front != Rear)
	{
		Front = (Front + 1) % MAX_SIZE_QUEUE;
		printf("Deque Data : %d\n", m_Data[Front]);
	}

	printf("=========================\n");
}
