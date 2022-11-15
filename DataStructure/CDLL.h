#pragma once

struct CDLL_Node
{
	int Data;
	CDLL_Node* Prev;
	CDLL_Node* Next;
};

class CDLL
{
private:
	CDLL_Node* m_Head;
	CDLL_Node* m_Tail;

public:
	CDLL();
	~CDLL();

public:
	void push_front(int data);
	void push_back(int data);
	void erase(int data);
	int get(int index);
	int size();
	bool empty();
};

