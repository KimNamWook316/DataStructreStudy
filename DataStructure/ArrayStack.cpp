#include <memory.h>
#include <iostream>
#include "ArrayStack.h"

CArrayStack::CArrayStack() :
	m_Top(-1)
{
	memset(m_Data, 0, sizeof(m_Data));
}

void CArrayStack::Push(int Data)
{
	if (IsFull())
	{
		return;
	}

	++m_Top;
	m_Data[m_Top] = Data;
}

void CArrayStack::Pop()
{
	if (IsEmpty())
	{
		return;
	}

	m_Data[m_Top] = 0;
	--m_Top;
}

int CArrayStack::Top()
{
	return m_Data[m_Top];
}

int CArrayStack::GetSize() const
{
	return m_Top + 1;
}

bool CArrayStack::IsEmpty() const
{
	return m_Top == -1;
}

bool CArrayStack::IsFull() const
{
	return m_Top >= STACK_SIZE_MAX - 1;
}

void CArrayStack::Print() const
{
	printf("== Stack Data == \n");
	for (int i = m_Top; i >= 0; --i)
	{
		printf("Data : %d\n", m_Data[i]);
	}
	printf("== end ==\n");
}
