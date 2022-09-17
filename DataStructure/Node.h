#pragma once

class CNode
{
public:
	CNode(int Data);

public:
	int GetData() const;
	void SetLink(CNode* Node);
	CNode* GetLink();
	void Print() const;

private:
	int m_Data;
	CNode* m_Link;
};

