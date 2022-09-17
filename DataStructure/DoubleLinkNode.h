#pragma once

class CDoubleLinkNode
{
public:
	CDoubleLinkNode(int data);

public:
	void SetPrev(CDoubleLinkNode* prev);
	void SetNext(CDoubleLinkNode* next);

	CDoubleLinkNode* GetPrev();
	CDoubleLinkNode* GetNext();

	CDoubleLinkNode* InsertPrev(int data);
	CDoubleLinkNode* InsertNext(int data);

	CDoubleLinkNode* DeletePrev();
	CDoubleLinkNode* DeleteNext();
	void Delete();

	void Print();

public:
	int GetData() const
	{
		return m_Data;
	}

	void SetData(int data);

private:
	CDoubleLinkNode* m_Prev;
	CDoubleLinkNode* m_Next;
	int m_Data;
};

