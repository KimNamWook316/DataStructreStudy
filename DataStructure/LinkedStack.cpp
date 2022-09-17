#include "LinkedStack.h"
#include <iostream>

CLinkedStack::CLinkedStack()    :
    m_Top(nullptr)
{
}

CLinkedStack::~CLinkedStack()
{
    CNode* node = m_Top;

    while (node)
    {
        CNode* next = node->GetLink();
        delete node;
        node = next;
    }
}

void CLinkedStack::Push(int Data)
{
    if (IsEmpty())
    {
        m_Top = new CNode(Data);
    }
    else
    {
        CNode* newTop = new CNode(Data);
        newTop->SetLink(m_Top);
        m_Top = newTop;
    }
}

void CLinkedStack::Pop()
{
    if (IsEmpty())
    {
        return;
    }

    CNode* newTop = m_Top->GetLink();
    delete m_Top;

    m_Top = newTop;
}

int CLinkedStack::Top()
{
    if (IsEmpty())
    {
        return -1;
    }

    return m_Top->GetData();
}

int CLinkedStack::GetSize() const
{
    int Count = 0;

    CNode* Node = m_Top;
    while (Node)
    {
        ++Count;
        Node = Node->GetLink();
    }

    return Count;
}

bool CLinkedStack::IsEmpty() const
{
    return m_Top == nullptr;
}

void CLinkedStack::Print() const
{
	printf("== Stack Data == \n");

    CNode* Node = m_Top;
    while (Node)
    {
        Node->Print();
        Node = Node->GetLink();
    }
    
	printf("== end ==\n");
}
