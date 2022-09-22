#pragma once

#include <list>

class CBinaryNode
{
public:
	CBinaryNode();
	CBinaryNode(char data);
	virtual ~CBinaryNode();

public:
	void SetData(char data)
	{
		m_Data = data;
	}

	char GetData()
	{
		return m_Data;
	}

	CBinaryNode* GetLeft();
	CBinaryNode* GetRight();
	void SetLeft(CBinaryNode* node);
	void SetRight(CBinaryNode* node);

	void Print();
	void InOrder();
	void PreOrder();
	void PostOrder();

	int GetCount();
	int GetLeafCount();
	int GetLevel();
	int IsLeaf();

	bool IsBalanced();
	int GetPathLength(int Level);
	bool Swap();
	void GetAllNode(std::list<CBinaryNode*>& outList);
	bool IsValid();

	CBinaryNode* SearchRecursive(char Key);

private:
	char m_Data;
	CBinaryNode* m_Left;
	CBinaryNode* m_Right;
};

