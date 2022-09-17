#include <iostream>
#include "ThreadBinaryTree.h"

CThreadBinaryTree::CThreadBinaryTree()	:
	m_Root(nullptr)
{
}

void CThreadBinaryTree::InOrder()
{
	std::cout << "Thread Binary Tree Inorder : ";

	if (m_Root)
	{
		CThreadBTNode* node = m_Root;

		while (node->GetLeft())
		{
			node = node->GetLeft();
		}

		do
		{
			if (!node)
			{
				break;
			}

			node->Print();

			// �ļ��ڸ� ã�´�.
			CThreadBTNode* successor = node->GetRight();

			// ������ ��尡 nullptr(��ȸ ��)�ų�, ���� ��尡 ������ ����� ���,
			// �� �̻� Ž������ �ʰ� nullptr, ���� ����� right�ļ��ڸ� ��ȯ�Ѵ�.
			if (successor == nullptr || node->IsThread())
			{
				node = successor;
			}
			// ���� ����� right ��尡 thread�� �ƴ� ���,
			// right����� ���� ���� ��尡 �ļӳ���̴�.
			else
			{
				while (successor->GetLeft())
				{
					successor = successor->GetLeft();
				}
			}

			node = successor;
		} while (true);
	}

	std::cout << "\n";
}
