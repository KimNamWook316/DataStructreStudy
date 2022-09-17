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

void TestCircleDeque();
void TestDoubleLinkedList();
void TestBracketCheck();
void TestBinaryTree();
void TestThreadBinaryTree();

int main()
{
	TestBinaryTree();

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

	std::string full = binTree.IsFull() ? "full" : "not full";

	std::cout << "Tree is " << full << '\n';
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
