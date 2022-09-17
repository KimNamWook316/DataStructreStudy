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

			// 후속자를 찾는다.
			CThreadBTNode* successor = node->GetRight();

			// 오른쪽 노드가 nullptr(순회 끝)거나, 현재 노드가 스레드 노드인 경우,
			// 더 이상 탐색하지 않고 nullptr, 현재 노드의 right후속자를 반환한다.
			if (successor == nullptr || node->IsThread())
			{
				node = successor;
			}
			// 현재 노드의 right 노드가 thread가 아닌 경우,
			// right노드의 왼쪽 끝의 노드가 후속노드이다.
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
