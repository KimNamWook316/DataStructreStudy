#include "CDLL.h"

CDLL::CDLL()
{
}

CDLL::~CDLL()
{
}

void CDLL::push_front(int data)
{
	if (nullptr == m_Head)
	{
		m_Head = new CDLL_Node;
		m_Head->Data = data;
		m_Head->Prev = m_Head;
		m_Head->Next = m_Head;
	}
	else
	{
		CDLL_Node* prev = m_Head->Next;

		m_Head->Next = new CDLL_Node;
		m_Head->Next->Data = data;

		m_Head->Next->Next = prev;

		if(prev)
			prev->Prev = m_Head->Next;
	}
}

void CDLL::push_back(int data)
{
	if (nullptr == m_Head)
	{
		m_Head = new CDLL_Node;
		m_Head->Data = data;
		m_Head->Prev = m_Head;
		m_Head->Next = m_Head;
	}
	else
	{
		if (!m_Tail)
		{
		}
		else
		{
		}
	}
}

