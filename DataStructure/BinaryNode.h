#pragma once

class CBinaryNode
{
public:
	CBinaryNode();
	CBinaryNode(char data);

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

private:
	char m_Data;
	CBinaryNode* m_Left;
	CBinaryNode* m_Right;
};

