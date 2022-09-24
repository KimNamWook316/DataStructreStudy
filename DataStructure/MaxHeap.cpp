#include <iostream>
#include <cmath>
#include "MaxHeap.h"

CMaxHeap::CMaxHeap()	:
	m_Size(0)
{
}

CMaxHeap::~CMaxHeap()
{
}

void CMaxHeap::Insert(int key)
{
	if (IsFull())
		return;

	int i = ++m_Size;

	while (i != 1)
	{
		if (key < m_NodeArr[i / 2].GetKey())
			break;
		else
		{
			m_NodeArr[i] = m_NodeArr[i / 2];
			i /= 2;
		}
	}

	m_NodeArr[i] = key;
}

CHeapNode CMaxHeap::Remove()
{
	if (IsEmpty())
		return NULL;

	CHeapNode root = m_NodeArr[1];
	CHeapNode last = m_NodeArr[m_Size--];

	int parent = 1;
	int child = 2;

	while (child <= m_Size)
	{
		if (m_NodeArr[child].GetKey() <= m_NodeArr[child + 1].GetKey())
			++child;

		if (m_NodeArr[child].GetKey() <= last.GetKey())
			break;

		m_NodeArr[parent].SetKey(m_NodeArr[child].GetKey());

		parent = child;
		child *= 2;
	}

	m_NodeArr[parent].SetKey(last.GetKey());

	return root;
}

bool CMaxHeap::IsEmpty()
{
	return m_Size == 0;
}

bool CMaxHeap::IsFull()
{
	return m_Size == max_Element - 1;
}

void CMaxHeap::Display()
{
	int level = 1;
	for (int i = 1; i <= m_Size; ++i)
	{
		m_NodeArr[i].Display();

		if (level * 2 == i + 1)
		{
			level *= 2;
			std::cout << '\n';
		}
	}
}
