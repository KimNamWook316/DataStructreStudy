#pragma once

#include "RedBlackNode.h"

class RedBlackTree
{
private:
	RedBlackNode* m_Root;

public:
	RedBlackTree();
	~RedBlackTree();

public:
	void Insert(int data);
	void Delete(int data);
	const RedBlackNode* Find(int data);

private:
	void RotateLeft(RedBlackNode* pivot);
	void RotateRight(RedBlackNode* pivot);
	void RebuildAfterInsert(RedBlackNode* insertNode);
};
