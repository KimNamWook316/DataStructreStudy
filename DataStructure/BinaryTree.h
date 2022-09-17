#pragma once

#include "BinaryNode.h"

class CBinaryTree
{
public:
	CBinaryTree();
	~CBinaryTree();

public:
	void SetRoot(CBinaryNode* root);
	bool IsEmpty();
	int GetCount();
	int GetHeight();
	int GetLeafCount();
	void LevelOrder();
	void InOrder();
	void PreOrder();
	void PostOrder();
	bool IsFull();
	int GetLevel();
	bool IsBalanced();
	int GetPathLength();
	bool Reverse();
	bool IsDisjointFrom(CBinaryTree* tree);
	bool IsValid();

private:
	CBinaryNode* m_Root;
};

