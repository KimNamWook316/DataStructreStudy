#pragma once

#include "BinaryTree.h"
class CBinSrchTree :
    public CBinaryTree
{
public:
    CBinSrchTree();
    virtual ~CBinSrchTree();

public:
    CBinaryNode* SearchRecursive(char key);
    CBinaryNode* SearchIterative(char key);
    bool Insert(CBinaryNode* node);
    bool Remove(char data);
};

