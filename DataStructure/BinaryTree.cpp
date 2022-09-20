#include <cstdio>
#include <queue>
#include "BinaryTree.h"

CBinaryTree::CBinaryTree()	:
	m_Root(nullptr)
{
}

CBinaryTree::~CBinaryTree()
{
}

void CBinaryTree::SetRoot(CBinaryNode* root)
{
	m_Root = root;
}

bool CBinaryTree::IsEmpty()
{
	return m_Root == nullptr;
}

int CBinaryTree::GetCount()
{
	if (!m_Root)
	{
		return 0;
	}

	return m_Root->GetCount();
}

int CBinaryTree::GetHeight()
{
	int height = 0;
	if (m_Root)
	{
		height = m_Root->GetLevel();
	}
	return height;
}

int CBinaryTree::GetLeafCount()
{
	int leafCount = 0;
	if (m_Root)
	{
		leafCount = m_Root->GetLeafCount();
	}

	return leafCount;
}

void CBinaryTree::LevelOrder()
{
	printf("LevelOrder\n");
	if (m_Root)
	{
		std::queue<CBinaryNode*> levelQueue;
		levelQueue.push(m_Root);

		while (!levelQueue.empty())
		{
			CBinaryNode* top = levelQueue.front();
			top->Print();

			if (top->GetLeft())
			{
				levelQueue.push(top->GetLeft());
			}
			if (top->GetRight())
			{
				levelQueue.push(top->GetRight());
			}

			levelQueue.pop();
		}
	}
	printf("===========================\n");
}

void CBinaryTree::InOrder()
{
	printf("InOrder\n");
	if (m_Root)
	{
		m_Root->InOrder();
	}
	printf("===========================\n");
}

void CBinaryTree::PreOrder()
{
	printf("PreOrder\n");
	if (m_Root)
	{
		m_Root->PreOrder();
	}
	printf("===========================\n");
}

void CBinaryTree::PostOrder()
{
	printf("PostOrder\n");
	if (m_Root)
	{
		m_Root->PostOrder();
	}
	printf("===========================\n");
}

bool CBinaryTree::IsFull()
{
	std::queue<CBinaryNode*> bQueue;
	bQueue.push(m_Root);

	while (!bQueue.empty())
	{
		bool meetNotFull = false;
		CBinaryNode* node = bQueue.front();

		// full node라면 계속 탐색한다.
		if (node->GetLeft() && node->GetRight())
		{
			bQueue.push(node->GetLeft());
			bQueue.push(node->GetRight());
			bQueue.pop();
		}
		else
		{
			// Full Node가 아닌 노드를 만났을 경우, 모든 노드가 단말 노드여야 한다.
			if (meetNotFull)
			{
				if (!node->IsLeaf())
					return false;
			}
			else
			{
				// 오른쪽만 있는 노드가 존재하면 완전 이진트리가 아니다
				if (!node->GetLeft() && node->GetRight())
					return false;

				// Full Node가 아닌 Node를 처음 만남
				meetNotFull = true;

				if (node->GetLeft())
					bQueue.push(node->GetLeft());

				bQueue.pop();
			}
		}
	}

	return true;
}

int CBinaryTree::GetLevel(CBinaryNode* node)
{
	if (!m_Root)
		return 0;

	int level = 1;
	int	nodeCount = 0;
	std::queue<CBinaryNode*> nodeQueue;
	nodeQueue.push(m_Root);

	// 레벨 순회
	while (!nodeQueue.empty())
	{
		++nodeCount;

		CBinaryNode* curNode = nodeQueue.front();

		// level의 높이를 가진 트리가 가질 수 있는 최대 노드 개수를 넘어간 경우
		if (pow(2, level) <= nodeCount)
		{
			++level;
		}

		if (curNode == node)
			return level;

		if (curNode->GetLeft())
			nodeQueue.push(curNode->GetLeft());

		if (curNode->GetRight())
			nodeQueue.push(curNode->GetRight());

		nodeQueue.pop();
	}

	return 0;
}

bool CBinaryTree::IsBalanced()
{
	if (!m_Root)
		return false;

	return m_Root->IsBalanced();
}

int CBinaryTree::GetPathLength()
{
	if (!m_Root)
		return false;

	return m_Root->GetPathLength(1);
}

bool CBinaryTree::Reverse()
{
	if (!m_Root)
		return false;

	return m_Root->Swap();
}

bool CBinaryTree::IsDisjointFrom(CBinaryTree* tree)
{
	if (!m_Root)
	{
		return true;
	}

	std::queue<CBinaryNode*> nodeQueue;
	nodeQueue.push(m_Root);

	while (!nodeQueue.empty())
	{
		CBinaryNode* curNode = nodeQueue.front();

		// other 트리가 현재 노드를 포함하고 있는지 확인
		if (tree->Include(curNode))
			return false;

		if (curNode->GetLeft())
			nodeQueue.push(curNode->GetLeft());

		if (curNode->GetRight())
			nodeQueue.push(curNode->GetRight());

		nodeQueue.pop();
	}

	return true;
}

bool CBinaryTree::IsValid()
{
	if (!m_Root)
		return true;

	bool valid = true;

	std::queue<CBinaryNode*> nodeQueue;
	nodeQueue.push(m_Root);

	while (!nodeQueue.empty())
	{
		CBinaryNode* curNode = nodeQueue.front();

		// left right 둘 다 있는 경우 Disjoint한지 확인한다.
		if (curNode->GetRight() && curNode->GetLeft())
		{
			CBinaryTree leftTree;
			leftTree.SetRoot(curNode->GetLeft());

			CBinaryTree rightTree;
			rightTree.SetRoot(curNode->GetRight());

			if (!leftTree.IsDisjointFrom(&rightTree))
				return false;
		}

		// left right가 Disjoint 하다면 left right가 각자 Valid한지 검사
		if (curNode->GetLeft())
		{
			CBinaryTree leftTree;
			leftTree.SetRoot(curNode->GetLeft());

			if (!leftTree.IsValid())
				return false;

			nodeQueue.push(curNode->GetLeft());
		}

		if (curNode->GetRight())
		{
			CBinaryTree rightTree;
			rightTree.SetRoot(curNode->GetRight());

			if (!rightTree.IsValid())
				return false;

			nodeQueue.push(curNode->GetRight());
		}

		nodeQueue.pop();
	}

	return true;
}

void CBinaryTree::GetAllNodes(std::list<CBinaryNode*>& outNodeList)
{
	if (m_Root)
		m_Root->GetAllNode(outNodeList);
}

bool CBinaryTree::Include(CBinaryNode* node)
{
	if (!m_Root)
		return false;

	std::queue<CBinaryNode*> nodeQueue;
	nodeQueue.push(m_Root);

	while (!nodeQueue.empty())
	{
		CBinaryNode* curNode = nodeQueue.front();

		if (curNode == node)
			return true;

		if (curNode->GetLeft())
			nodeQueue.push(curNode->GetLeft());

		if (curNode->GetRight())
			nodeQueue.push(curNode->GetRight());

		nodeQueue.pop();
	}

	return false;
}

bool CBinaryTree::IsEmpty() const
{
	if (m_Root)
		return false;
	else
		return true;
}
