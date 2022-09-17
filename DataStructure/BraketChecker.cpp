#include <cstdio>
#include "BraketChecker.h"

CBraketChecker::CBraketChecker()
{
}

bool CBraketChecker::Check(const char* filePath)
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, filePath, "r");

	if (fp == nullptr)
	{
		printf("File Error\n");
		return false;
	}

	char ch = getc(fp);

	while (ch != EOF)
	{
		if (ch == ')' || ch == '}' || ch == ']')
		{
			// 오른쪽 괄호가 먼저 나온 경우
			if (m_Stack.IsEmpty())
			{
				fclose(fp);
				return false;
			}
			else
			{
				// 괄호 짝이 맞는 경우
				if ((ch == ')' && m_Stack.Top() == '(') ||
					(ch == '}' && m_Stack.Top() == '{') ||
					(ch == ']' && m_Stack.Top() == '['))
				{
					m_Stack.Pop();
				}
				// 괄호 짝이 맞지 않는 경우
				else
				{
					fclose(fp);
					return false;
				}
			}
		}
		// 왼쪽 괄호
		else if (ch == '(' || ch == '{' || ch == '[')
		{
			m_Stack.Push(ch);
		}
		else
		{
			ch = getc(fp);
			continue;
		}

		ch = getc(fp);
	}

	fclose(fp);

	return m_Stack.IsEmpty();
}
