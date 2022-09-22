#include <iostream>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "CircleQueue.h"
#include "LinkedQueue.h"
#include "CircleDeque.h"
#include "DoubleLinkedList.h"
#include "BraketChecker.h"
#include "BinaryTree.h"
#include "ThreadBinaryTree.h"
#include "BinSrchTree.h"
#include "Dictionary.h":

void TestCircleDeque();
void TestDoubleLinkedList();
void TestBracketCheck();
void TestBinaryTree();
void TestThreadBinaryTree();
void TestBinarySearchTree();
void TestDictionary();

int main()
{
	TestDictionary();

	return 0;
}

void TestCircleDeque()
{
	CCircleDeque deque;

	deque.AddFront(4);
	deque.AddRear(5);

	deque.Print();

	deque.AddFront(3);
	deque.AddRear(6);

	deque.Print();

	deque.DeleteFront();
	deque.Print();

	deque.DeleteRear();
	deque.Print();

	deque.DeleteFront();
	deque.DeleteFront();
	deque.Print();

	deque.AddFront(4);
	deque.AddFront(4);
	deque.AddFront(4);
	deque.AddFront(4);
	deque.DeleteRear();
	deque.DeleteRear();
	deque.DeleteRear();
	deque.DeleteRear();
	deque.Print();
}

void TestDoubleLinkedList()
{
	CDoubleLinkedList list;

	list.PushBack(3);
	list.PushBack(2);
	list.PushBack(1);

	list.Print();

	list.PushFront(4);
	list.PushFront(5);
	list.PushFront(6);

	list.Print();

	list.Insert(0, 8);
	list.Print();

	list.Insert(1, 7);
	list.Print();

	list.Insert(7, -1);
	list.Print();

	list.PopFront();
	list.PopFront();
	list.Print();

	list.PopBack();
	list.PopBack();
	list.Print();

	list.Erase(0);
	list.Print();

	list.Erase(3);
	list.Print();

	list.Erase(1);
	list.Print();

	list.Replace(1, 4);
	list.Print();

	list.Clear();
	list.Print();
}

void TestBracketCheck()
{
	CBraketChecker checker;
	bool Check = checker.Check("BracketTest.txt");

	std::cout << Check << std::endl;
}

void TestBinaryTree()
{
	CBinaryTree binTree;
	CBinaryTree binTree2;

	CBinaryNode* a = new CBinaryNode('A');
	CBinaryNode* b = new CBinaryNode('B');
	CBinaryNode* c = new CBinaryNode('C');
	CBinaryNode* d = new CBinaryNode('D');
	CBinaryNode* e = new CBinaryNode('E');
	CBinaryNode* f = new CBinaryNode('F');

	b->SetLeft(c);
	b->SetRight(d);
	a->SetLeft(b);
	a->SetRight(e);
	e->SetRight(f);

	binTree.SetRoot(a);

	CBinaryNode* g = new CBinaryNode('G');
	g->SetLeft(f);
	binTree2.SetRoot(g);

	std::string full = binTree.IsFull() ? "full" : "not full";

	std::cout << "Tree is " << full << '\n';

	int level = binTree.GetLevel(b);
	std::cout << "node f level : " << level << '\n';

	bool balanced = binTree.IsBalanced();
	std::cout << "Tree Balanced : " << std::boolalpha << balanced << '\n';

	int pathLength = binTree.GetPathLength();
	std::cout << "Tree Path Length : " << pathLength << '\n';

	bool swap = binTree.Reverse();
	std::cout << "After Reverse\n";

	binTree.LevelOrder();

	bool disjoint = binTree.IsDisjointFrom(&binTree2);
	std::cout << "tree disjoint from tree2 is : " << std::boolalpha << disjoint << '\n';

	bool valid = binTree.IsValid();
	std::cout << "tree 1 valid : " << std::boolalpha << valid << '\n';

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

void TestThreadBinaryTree()
{
	CThreadBinaryTree tree;

	//						1	
	//				2				3	
	//			4		5				8	
	//				  6   7					9

	CThreadBTNode* n6 = new CThreadBTNode('6', nullptr, nullptr, true);
	CThreadBTNode* n7 = new CThreadBTNode('7', nullptr, nullptr, true);
	CThreadBTNode* n5 = new CThreadBTNode('5', n6, n7, true);

	CThreadBTNode* n4 = new CThreadBTNode('4', nullptr, nullptr, true);
	CThreadBTNode* n2 = new CThreadBTNode('2', n4, n5, false);

	CThreadBTNode* n9 = new CThreadBTNode('9', nullptr, nullptr, false);
	CThreadBTNode* n8 = new CThreadBTNode('8', nullptr, n9, false);
	CThreadBTNode* n3 = new CThreadBTNode('3', nullptr, n8, false);

	CThreadBTNode* n1 = new CThreadBTNode('1', n2, n3, false);

	n4->SetRight(n2);
	n6->SetRight(n5);
	n7->SetRight(n1);

	tree.SetRoot(n1);
	tree.InOrder();

	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;
	delete n6;
	delete n7;
	delete n8;
	delete n9;
}

void TestBinarySearchTree()
{
	CBinSrchTree tree;

	tree.Insert(new CBinaryNode(35));
	tree.Insert(new CBinaryNode(18));
	tree.Insert(new CBinaryNode(7));
	tree.Insert(new CBinaryNode(26));
	tree.Insert(new CBinaryNode(12));
	tree.Insert(new CBinaryNode(3));
	tree.Insert(new CBinaryNode(68));
	tree.Insert(new CBinaryNode(22));
	tree.Insert(new CBinaryNode(30));
	tree.Insert(new CBinaryNode(99));

	std::cout << "노드의 개수 : " << tree.GetCount() << '\n';
	std::cout << "단말의 개수 : " << tree.GetLeafCount() << '\n';
	std::cout << "트리의 높이 : " << tree.GetHeight() << '\n';

	// 순회
	tree.InOrder();
	tree.PreOrder();
	tree.PostOrder();
	tree.LevelOrder();

	// 탐색
	tree.SearchIterative(26);
	tree.SearchRecursive(25);

	// 삭제
	std::cout << "Case 1 : Node 3 삭제\n";
	tree.Remove(3);
	tree.LevelOrder();

	std::cout << "Case 2 : Node 68 삭제\n";
	tree.Remove(68);
	tree.LevelOrder();

	std::cout << "Case 3 : Node 18 삭제\n";
	tree.Remove(18);
	tree.LevelOrder();

	std::cout << "Case 4 : Node 35 삭제\n";
	tree.Remove(35);
	tree.LevelOrder();

	std::cout << "노드의 개수 : " << tree.GetCount() << '\n';
	std::cout << "단말의 개수 : " << tree.GetLeafCount() << '\n';
	std::cout << "트리의 높이 : " << tree.GetHeight() << '\n';
}

void TestDictionary()
{
	CDictionary dic;

	char input = 0;

	bool dicSuccess = true;
	std::string word = "";
	std::string mean = "";

	while (input != 'q')
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

		std::cout << "[사용법] " << "i-추가 d-삭제 w-단어검색 p-출력 q-종료 >>";

		std::cin >> input;

		if (input == 'i')
		{
			std::cout << "\n삽입 단어 : ";
			std::cin >> word;
			std::cout << "\n단어 설명 : ";
			std::cin >> mean;

			dicSuccess = dic.Insert(word, mean);

			if (!dicSuccess)
			{
				std::cout << "단어 삽입 실패 : 중복된 단어" << std::endl;
			}
		}
		else if (input == 'd')
		{
			std::cout << "\n삭제 단어 : ";
			std::cin >> word;

			dicSuccess = dic.Remove(word);

			if (!dicSuccess)
			{
				std::cout << "단어 삭제 실패 : 삭제하려는 단어가 없음" << std::endl;
			}
		}
		else if (input == 'w')
		{
			std::cout << "\n찾으려는 단어 : ";
			std::cin >> word;

			CDicRecord* find = dic.SearchWord(word);

			if (find)
			{
				find->Display();
			}
			else
			{
				std::cout << "단어 검색 실패 : 단어가 없음" << std::endl;
			}
		}
		else if (input == 'p')
		{
			dic.PrintRecord();
		}
		else if (input == 'q')
		{
			std::cout << "종료" << std::endl;
		}
		else
		{
			std::cout << "잘못된 명령어" << std::endl;
		}
	}
}
