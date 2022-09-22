#include <iostream>
#include <queue>
#include "Dictionary.h"
#include "DicRecord.h"

CDictionary::CDictionary()	:
	m_Root(nullptr)
{
}

CDictionary::~CDictionary()
{
	if (m_Root)
	{
		std::queue<CDicRecord*> recQueue;
		recQueue.push(m_Root);
		CDicRecord* rec = nullptr;

		while (!recQueue.empty())
		{
			rec = recQueue.front();

			if (rec->GetLeft())
				recQueue.push(rec->GetLeft());

			if (rec->GetRight())
				recQueue.push(rec->GetRight());

			recQueue.pop();

			delete rec;
		}
	}
}

CDicRecord* CDictionary::SearchWord(const std::string& word)
{
	if (!m_Root)
	{
		std::cout << "찾고자 하는 단어 " << word << " 가 존재하지 않습니다.\n";
		return nullptr;
	}

	CDicRecord* curNode = m_Root;

	int compare = 0;
	while (curNode)
	{
		compare = curNode->Compare(word);

		if (compare == 0)
		{
			return curNode;
		}
		else if (compare == -1)
		{
			curNode = curNode->GetLeft();
		}
		else
		{
			curNode = curNode->GetRight();
		}
	}

	std::cout << "찾고자 하는 단어 " << word << " 가 존재하지 않습니다.\n";
	return nullptr;
}

bool CDictionary::Insert(const std::string& word, const std::string& meaning)
{
	if (!m_Root)
	{
		m_Root = new CDicRecord(word, meaning);
		return true;
	}
	
	CDicRecord* curNode = m_Root;

	int compare = 0;
	while (curNode)
	{
		compare = curNode->Compare(word);

		if (compare == 0)
		{
			return false;
		}
		else if (compare == 1)
		{
			if (curNode->GetLeft())
			{
				curNode = curNode->GetLeft();
			}
			else
			{
				curNode->SetLeft(new CDicRecord(word, meaning));
				return true;
			}
		}
		else if (compare == -1)
		{
			if (curNode->GetRight())
			{
				curNode = curNode->GetRight();
			}
			else
			{
				curNode->SetRight(new CDicRecord(word, meaning));
				return true;
			}
		}
	}

	return false;
}

bool CDictionary::Remove(const std::string& word)
{
	CDicRecord* parent = nullptr;
	CDicRecord* curNode = m_Root;

	int compare = 0;
	while (curNode)
	{
		compare = curNode->Compare(word);

		if (compare == 0)
		{
			if (curNode->IsLeaf())
			{
				if (curNode == m_Root)
				{
					m_Root = nullptr;
				}

				if (parent)
				{
					if (parent->GetLeft() == curNode)
						parent->SetLeft(nullptr);
					else
						parent->SetRight(nullptr);
				}
			}
			else if (!curNode->GetLeft() || !curNode->GetRight())
			{
				CDicRecord* succ = curNode->GetLeft() ? curNode->GetLeft() : curNode->GetRight();

				if (curNode == m_Root)
				{
					m_Root = succ;
				}
				else
				{
					if (parent->GetLeft() == curNode)
					{
						parent->SetLeft(succ);
					}
					else
					{
						parent->SetRight(succ);
					}
				}
			}
			else
			{
				CDicRecord* succ = curNode->GetRight();
				CDicRecord* succParent = curNode;

				while (succ->GetLeft())
				{
					succParent = succ;
					succ = succ->GetLeft();
				}

				// Delete Root
				if (m_Root == curNode)
				{
					m_Root = succ;
				}

				if (parent)
				{
					if (parent->GetLeft() == curNode)
					{
						parent->SetLeft(succ);
					}
					else
					{
						parent->SetRight(succ);
					}
				}

				if (curNode->GetRight() != succ)
				{
					succParent->SetLeft(succ->GetRight());
					succ->SetRight(curNode->GetRight());
				}

				succ->SetLeft(curNode->GetLeft());
			}

			delete curNode;
			return true;
		}
		else
		{
			parent = curNode;

			if (compare == 1)
			{
				curNode = curNode->GetLeft();
			}
			else
			{
				curNode = curNode->GetRight();
			}
		}
	}

	return false;
}

void CDictionary::PrintRecord()
{
	std::cout << "단어 목록" << std::endl;
	std::cout << "============================================" << std::endl;

	if (m_Root)
	{
		m_Root->InOrder();
	}

	std::cout << "============================================" << std::endl;
}
