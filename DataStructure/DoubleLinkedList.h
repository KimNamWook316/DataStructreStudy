#pragma once

#include "DoubleLinkNode.h"

class CDoubleLinkedList
{
public:
	CDoubleLinkedList();
	~CDoubleLinkedList();

public:
	void PushBack(int data);
	void PushFront(int data);
	int PopBack();
	int PopFront();
	void Erase(int pos);
	void Insert(int pos, int data);
	void Replace(int pos, int Data);
	void Clear();
	bool IsEmpty();
	void Print();

	int GetSize() const
	{
		return m_Size;
	}

private:
	CDoubleLinkNode* GetNode(int pos);

private:
	CDoubleLinkNode* m_Front;
	CDoubleLinkNode* m_Back;
	int m_Size;
};

