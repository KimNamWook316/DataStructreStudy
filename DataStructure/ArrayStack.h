#pragma once

#define STACK_SIZE_MAX 100

class CArrayStack
{
public:
	CArrayStack();

public:
	void Push(int Data);
	void Pop();
	int Top();
	int GetSize() const;
	bool IsEmpty() const;
	bool IsFull() const;
	void Print() const;

private:
	int m_Top;
	int m_Data[STACK_SIZE_MAX];
};

