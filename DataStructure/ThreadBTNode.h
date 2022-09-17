#pragma once

class CThreadBTNode
{
public:
	CThreadBTNode(char data);
	CThreadBTNode(char data, CThreadBTNode* left, CThreadBTNode* right, bool thread);

public:
	void Print() const;

	void SetThread(bool thread)
	{
		m_Thread = thread;
	}

	bool IsThread() const
	{
		return m_Thread;
	}

	void SetLeft(CThreadBTNode* node)
	{
		m_Left = node;
	}

	void SetRight(CThreadBTNode* node)
	{
		m_Right= node;
	}

	CThreadBTNode* GetLeft() const
	{
		return m_Left;
	}

	CThreadBTNode* GetRight() const
	{
		return m_Right;
	}

	char GetData() const
	{
		return m_Data;
	}

private:
	char m_Data;
	bool m_Thread;
	CThreadBTNode* m_Left;
	CThreadBTNode* m_Right;
};

