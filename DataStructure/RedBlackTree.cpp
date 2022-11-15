#include "RedBlackTree.h"

RedBlackNode NIL = RedBlackNode(-1, RedBlackNode::Color::BLACK);

RedBlackTree::RedBlackTree()	:
	m_Root(nullptr)
{
	m_Root = &NIL;
}

RedBlackTree::~RedBlackTree()
{
	if (m_Root != &NIL)
		m_Root->Clear();
}

void RedBlackTree::Insert(int data)
{
	if (m_Root == &NIL)
	{
		m_Root = new RedBlackNode(data, RedBlackNode::Color::BLACK);
		m_Root->SetLeft(&NIL);
		m_Root->SetRight(&NIL);
	}
	else
	{
		RedBlackNode* node = m_Root;

		while(true)
		{
			// 중복된 데이터 있는 경우
			if (node->GetData() == data)
				break;

			// 현재 노드보다 삽입할 데이터가 작은 경우
			else if (node->GetData() > data)
			{
				if (node->GetLeft() != &NIL)
					node = node->GetLeft();

				// 왼쪽 자리가 비어있는 경우 삽입
				else
				{
					// 새로운 노드는 언제나 RED
					RedBlackNode* newNode = new RedBlackNode(data, RedBlackNode::Color::RED);
					node->SetLeft(newNode);
					newNode->SetParent(node);

					// 새로운 노드의 왼쪽, 오른쪽은 NIL
					newNode->SetLeft(&NIL);
					newNode->SetRight(&NIL);

					// 삽입 후 트리 재구성
					RebuildAfterInsert(newNode);
					break;
				}
			}

			// 현재 노드보다 삽입할 데이터가 큰 경우
			else
			{
				if (node->GetRight() != &NIL)
					node = node->GetRight();

				// 오른쪽 자리가 비어있는 경우 삽입
				else
				{
					// 새로운 노드는 언제나 RED
					RedBlackNode* newNode = new RedBlackNode(data, RedBlackNode::Color::RED);
					node->SetRight(newNode);
					newNode->SetParent(node);

					// 새로운 노드의 왼쪽, 오른쪽은 NIL
					newNode->SetLeft(&NIL);
					newNode->SetRight(&NIL);

					// 삽입 후 트리 재구성
					RebuildAfterInsert(newNode);
					break;
				}
			}
		}
	}
}

void RedBlackTree::Delete(int data)
{
}

const RedBlackNode* RedBlackTree::Find(int data)
{
	RedBlackNode* find = m_Root;

	while(find != nullptr)
	{
		if (find->GetData() == data)
			return find;
		else if (find->GetData() > data)
			find = find->GetLeft();
		else
			find = find->GetRight();
	}

	return nullptr;
}

void RedBlackTree::RotateLeft(RedBlackNode* pivot)
{
	RedBlackNode* pivotParent = pivot->GetParent();
	RedBlackNode* child = pivot->GetRight();
	RedBlackNode* childLeftChild = child->GetLeft();

	// pivot의 부모가 null인 경우 : pivot이 Root이다.
	if (nullptr == pivotParent)
		m_Root = child;
	// pivot이 부모의 왼쪽 자식인 경우
	else if (pivotParent->GetLeft() == pivot)
	{
		pivotParent->SetLeft(child);
		child->SetParent(pivotParent);
	}
	// pivot이 부모의 오른쪽 자식인 경우
	else
	{
		pivotParent->SetRight(child);
		child->SetParent(pivotParent);
	}

	// pivot을 child의 왼쪽 자식으로 내리고, child의 왼쪽 자식을 pivot의 오른쪽 자식으로 붙인다.
	child->SetLeft(pivot);
	pivot->SetParent(child);
	pivot->SetRight(childLeftChild);
}

void RedBlackTree::RotateRight(RedBlackNode* pivot)
{
	RedBlackNode* pivotParent = pivot->GetParent();
	RedBlackNode* child = pivot->GetLeft();
	RedBlackNode* childRightChild = child->GetRight();

	// pivot의 부모가 null인 경우 : pivot이 Root이다.
	if (nullptr == pivotParent)
		m_Root = child;
	// pivot이 부모의 왼쪽 자식인 경우
	else if (pivotParent->GetLeft() == pivot)
	{
		pivotParent->SetLeft(child);
		child->SetParent(pivotParent);
	}
	// pivot이 부모의 오른쪽 자식인 경우
	else
	{
		pivotParent->SetRight(child);
		child->SetParent(pivotParent);
	}

	// pivot을 child의 오른쪽 자식으로 내리고, child의 오른쪽 자식을 pivot의 왼쪽 자식으로 붙인다.
	child->SetRight(pivot);
	pivot->SetParent(child);
	pivot->SetLeft(childRightChild);
}

void RedBlackTree::RebuildAfterInsert(RedBlackNode* insertNode)
{
	RedBlackNode* insert = insertNode;
	RedBlackNode* parent = insert->GetParent();

	// 부모 노드의 색이 검은색이라면 재조정 필요 없음
	// 여기서 부모 노드가 루트인 경우도 걸러진다.
	if (parent->GetColor() == RedBlackNode::Color::BLACK)
		return;

	// 조부 노드를 구한다.
	RedBlackNode* grandParent = parent->GetParent();

	// 삽입 된 노드가 루트가 되거나 ( 조정 이후 삽입이 되었다고 판정하는 노드가 바뀔 수 있음 )
	// 삽입 된 노드의 부모가 검은색이 될 때까지 구조를 변경한다.
	while(insert != m_Root && parent->GetColor() == RedBlackNode::Color::RED)
	{
		// 삼촌 노드를 구한다.
		RedBlackNode* uncle = nullptr;
		const bool parentIsLeftChild = grandParent->GetLeft() == parent ? true : false;

		if (parentIsLeftChild)
			uncle = grandParent->GetRight();
		else
			uncle = grandParent->GetLeft();

		// CASE 1 : 삼촌이 빨간색인 경우 -> 조부를 빨간색, 부모와 삼촌을 검은색으로
		if (uncle->GetColor() == RedBlackNode::Color::RED)
		{
			parent->SetColor(RedBlackNode::Color::BLACK);
			uncle->SetColor(RedBlackNode::Color::BLACK);
			grandParent->SetColor(RedBlackNode::Color::RED);

			// 만약 조부가 루트라면 다시 검은색으로 되돌리고 루프 종료
			if (grandParent == m_Root)
			{
				grandParent->SetColor(RedBlackNode::Color::BLACK);
				break;
			}

			// 조부 노드가 빨간색이 되었으므로 다시 조건을 체크하기 위해
			// 조부 노드를 새로 삽입된 노드로 간주하여 다시 체크
			insert = grandParent;
			parent = insert->GetParent();
			grandParent = parent->GetParent();
		}
		// 삼촌 노드가 검은색인 경우
		// 부모 노드가 조부 노드의 오른쪽 노드인지 왼쪽 노드인지에 따라 
		// 부모 노드가 조부 노드의 왼쪽 노드인 경우
		else if (parentIsLeftChild)
		{
			// CASE 2 : 조부 - 부모 - 삽입 노드가 일직선이 아닌 경우 -> CASE 3로 형태를 바꾼다.
			if (insert == parent->GetRight())
			{
				// 부모 기준으로 왼쪽 회전하고, 부모 노드를 새로 삽입한 노드로 간주한다.
				RotateLeft(parent);

				// 조부와 삼촌 노드는 바뀌지 않는다.
				insert = parent;
				parent = insert->GetParent();
			}
			// CASE 3 : 조부 - 부모 - 삽입 노드가 일직선인 경우 
			else
			{
				// 조부를 빨간색, 부모를 검은색으로 바꾸고 조부 기준으로 오른쪽 회전한다.
				grandParent->SetColor(RedBlackNode::Color::RED);
				parent->SetColor(RedBlackNode::Color::BLACK);
				RotateRight(grandParent);
			}
		}
		// 부모 노드가 조부 노드의 오른쪽 노드인 경우
		else
		{
			// CASE 2 : 조부 - 부모 - 삽입 노드가 일직선이 아닌 경우 -> CASE 3로 형태를 바꾼다.
			if (insert == parent->GetLeft())
			{
				// 부모 기준으로 오른쪽 회전하고, 부모 노드를 새로 삽입한 노드로 간주한다.
				RotateRight(parent);

				// 조부와 삼촌 노드는 바뀌지 않는다.
				insert = parent;
				parent = insert->GetParent();
			}
			// CASE 3 : 조부 - 부모 - 삽입 노드가 일직선인 경우 
			else
			{
				// 조부를 빨간색, 부모를 검은색으로 바꾸고 조부 기준으로 왼쪽 회전한다.
				grandParent->SetColor(RedBlackNode::Color::RED);
				parent->SetColor(RedBlackNode::Color::BLACK);
				RotateLeft(grandParent);
			}
		}
	}
}
