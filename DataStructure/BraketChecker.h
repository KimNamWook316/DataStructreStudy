#pragma once

#include "LinkedStack.h"

class CBraketChecker
{
public:
	CBraketChecker();

public:
	bool Check(const char* filePath);

private:
	CLinkedStack m_Stack;
};

