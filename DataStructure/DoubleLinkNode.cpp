#include <iostream>
#include "DoubleLinkNode.h"

CDoubleLinkNode::CDoubleLinkNode(int data) :
    m_Prev(nullptr),
    m_Next(nullptr),
    m_Data(data)
{
}

void CDoubleLinkNode::SetPrev(CDoubleLinkNode* prev)
{
    m_Prev = prev;
}

void CDoubleLinkNode::SetNext(CDoubleLinkNode* next)
{
    m_Next = next;
}

CDoubleLinkNode* CDoubleLinkNode::GetPrev()
{
    return m_Prev;
}

CDoubleLinkNode* CDoubleLinkNode::GetNext()
{
    return m_Next;
}

CDoubleLinkNode* CDoubleLinkNode::InsertPrev(int data)
{
    CDoubleLinkNode* newPrev = new CDoubleLinkNode(data);

    if (m_Prev)
    {
		m_Prev->SetNext(newPrev);
    }

    newPrev->SetPrev(m_Prev);
    newPrev->SetNext(this);

    m_Prev = newPrev;

    return newPrev;
}

CDoubleLinkNode* CDoubleLinkNode::InsertNext(int data)
{
    CDoubleLinkNode* newNext = new CDoubleLinkNode(data);

    if (m_Next)
    {
		m_Next->SetPrev(newNext);
    }

    newNext->SetNext(m_Next);
    newNext->SetPrev(this);

    m_Next = newNext;

    return newNext;
}

CDoubleLinkNode* CDoubleLinkNode::DeletePrev()
{
    if (!m_Prev)
    {
        return nullptr;
    }

    CDoubleLinkNode* newPrev = m_Prev->GetPrev();

    if (newPrev)
    {
		delete m_Prev;
        SetNext(this);
        m_Prev = newPrev;
    }

    return m_Prev;
}

CDoubleLinkNode* CDoubleLinkNode::DeleteNext()
{
    if (!m_Next)
    {
        return nullptr;
    }

    CDoubleLinkNode* newNext = m_Next->GetNext();

    if (newNext)
    {
		delete m_Next;
        newNext->SetPrev(this);
        m_Next = newNext;
    }

    return newNext;
}

void CDoubleLinkNode::Delete()
{
    if (m_Prev)
    {
        m_Prev->SetNext(m_Next);
    }

	if (m_Next)
	{
		m_Next->SetPrev(m_Prev);
	}

    delete this;
}

void CDoubleLinkNode::Print()
{
    printf(" [%d] ", m_Data);
}

void CDoubleLinkNode::SetData(int data)
{
    m_Data = data;
}
