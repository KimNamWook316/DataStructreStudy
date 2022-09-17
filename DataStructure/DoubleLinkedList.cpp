#include <iostream>
#include "DoubleLinkedList.h"

CDoubleLinkedList::CDoubleLinkedList()	:
	m_Front(nullptr),
	m_Back(nullptr),
	m_Size(0)
{
}

CDoubleLinkedList::~CDoubleLinkedList()
{
	Clear();
}

void CDoubleLinkedList::PushBack(int data)
{
	if (IsEmpty())
	{
		CDoubleLinkNode* newNode = new CDoubleLinkNode(data);
		m_Front = newNode;
		m_Back = newNode;
	}
	else
	{
		CDoubleLinkNode* back = m_Back->InsertNext(data);
		m_Back = back;
	}

	++m_Size;
}

void CDoubleLinkedList::PushFront(int data)
{
	if (IsEmpty())
	{
		CDoubleLinkNode* newNode = new CDoubleLinkNode(data);
		m_Front = newNode;
		m_Back = newNode;
	}
	else
	{
		CDoubleLinkNode* front = m_Front->InsertPrev(data);
		m_Front = front;
	}

	++m_Size;
}

int CDoubleLinkedList::PopBack()
{
	if (IsEmpty())
	{
		return -1;
	}

	CDoubleLinkNode* back = m_Back->GetPrev();

	int data = m_Back->GetData();

	m_Back->Delete();

	if (back == nullptr)
	{
		m_Front = nullptr;
	}

	m_Back = back;

	--m_Size;

	return data;
}

int CDoubleLinkedList::PopFront()
{
	if (IsEmpty())
	{
		return -1;
	}

	CDoubleLinkNode* front = m_Front->GetNext();

	int data = m_Front->GetData();

	m_Front->Delete();

	if (front == m_Back)
	{
		m_Back = nullptr;
	}

	m_Front = front;

	--m_Size;

	return data;
}

void CDoubleLinkedList::Erase(int pos)
{
	if (m_Size - 1 < pos)
	{
		return;
	}

	if (pos == 0)
	{
		PopFront();
	}
	else if (pos == m_Size - 1)
	{
		PopBack();
	}
	else
	{
		CDoubleLinkNode* node = GetNode(pos);

		node->Delete();
		--m_Size;
	}
}

void CDoubleLinkedList::Insert(int pos, int data)
{
	if (m_Size - 1 < pos)
	{
		return;
	}

	if (pos == 0)
	{
		PushFront(data);
	}
	else if (pos == m_Size - 1)
	{
		PushBack(data);
	}
	else
	{
		CDoubleLinkNode* node = GetNode(pos);

		node->InsertPrev(data);
		++m_Size;
	}
}

void CDoubleLinkedList::Replace(int pos, int Data)
{
	CDoubleLinkNode* node = GetNode(pos);
	
	if (node)
	{
		node->SetData(Data);
	}
}

void CDoubleLinkedList::Clear()
{
	CDoubleLinkNode* node = m_Front;

	while (node)
	{
		CDoubleLinkNode* next = node->GetNext();
		node->Delete();
		node = next;
	}

	m_Front = nullptr;
	m_Back = nullptr;

	m_Size = 0;
}

bool CDoubleLinkedList::IsEmpty()
{
	return (m_Size == 0);
}

void CDoubleLinkedList::Print()
{
	CDoubleLinkNode* node = m_Front;

	printf("Double Linked List Data : ");
	while (node)
	{
		node->Print();
		node = node->GetNext();
	}
	printf("\n");
}

CDoubleLinkNode* CDoubleLinkedList::GetNode(int pos)
{
	if (pos > m_Size - 1)
	{
		return nullptr;
	}

	if (pos == 0)
	{
		return m_Front;
	}
	else if (pos == m_Size - 1)
	{
		return m_Back;
	}
	else
	{
		CDoubleLinkNode* node = m_Front;

		int count = 0;
		while (count < pos)
		{
			node = node->GetNext();
			++count;
		}

		return node;
	}
}
