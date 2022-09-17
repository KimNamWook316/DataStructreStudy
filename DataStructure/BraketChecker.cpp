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
			// ������ ��ȣ�� ���� ���� ���
			if (m_Stack.IsEmpty())
			{
				fclose(fp);
				return false;
			}
			else
			{
				// ��ȣ ¦�� �´� ���
				if ((ch == ')' && m_Stack.Top() == '(') ||
					(ch == '}' && m_Stack.Top() == '{') ||
					(ch == ']' && m_Stack.Top() == '['))
				{
					m_Stack.Pop();
				}
				// ��ȣ ¦�� ���� �ʴ� ���
				else
				{
					fclose(fp);
					return false;
				}
			}
		}
		// ���� ��ȣ
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
