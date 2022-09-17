#include <iostream>
#include "LinkedQueue.h"

CLinkedQueue::CLinkedQueue()	:
	m_Front(nullptr),
	m_Rear(nullptr)
{
}

CLinkedQueue::~CLinkedQueue()
{
	while (!IsEmpty())
	{
		Dequeue();
	}
}

void CLinkedQueue::Enqueue(int data)
{
	CNode* newNode = new CNode(data);

	if (IsEmpty())
	{
		m_Front = newNode;
	}

	if (m_Rear)
	{
		m_Rear->SetLink(newNode);
	}

	m_Rear = newNode;
}

int CLinkedQueue::Dequeue()
{
	if (IsEmpty())
	{
		return -1;
	}

	CNode* newFront = m_Front->GetLink();

	int data = m_Front->GetData();
	delete m_Front;

	m_Front = newFront;

	if (m_Front == nullptr)
	{
		m_Rear = nullptr;
	}

	return data;
}

int CLinkedQueue::Front()
{
	if (IsEmpty())
	{
		return -1;
	}

	return m_Front->GetData();
}

bool CLinkedQueue::IsEmpty()
{
	return m_Front == nullptr;
}

void CLinkedQueue::Print()
{
	printf("=== Circle Queue Data ===\n");
	CNode* node = m_Front;

	while (node)
	{
		printf("Queue Data : %d\n", node->GetData());
		node = node->GetLink();
	}

	printf("=========================\n");
}

int CLinkedQueue::Size()
{
	CNode* node = m_Front;

	int size = 0;
	while (node)
	{
		++size;
		node = node->GetLink();
	}

	return size;
}
