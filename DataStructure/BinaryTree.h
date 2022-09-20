#pragma once

#include "BinaryNode.h"

class CBinaryTree
{
public:
	CBinaryTree();
	virtual ~CBinaryTree();

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
	int GetLevel(CBinaryNode* node);
	bool IsBalanced();
	int GetPathLength();
	bool Reverse();
	bool IsDisjointFrom(CBinaryTree* tree);
	bool IsValid();
	void GetAllNodes(std::list<CBinaryNode*>& outNodeList);
	bool Include(CBinaryNode* node);

public:
	bool IsEmpty() const;

protected:
	CBinaryNode* m_Root;
};

