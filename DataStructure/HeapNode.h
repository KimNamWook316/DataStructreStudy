#pragma once

class CHeapNode
{
public:
	CHeapNode();
	CHeapNode(int key);
	~CHeapNode();

public:
	void Display();

public:
	void SetKey(int key)
	{
		m_Key = key;
	}

	int GetKey() const
	{
		return m_Key;
	}

private:
	int m_Key;
};

