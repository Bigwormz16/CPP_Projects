#include "test_15_LinkedList.h"
#include <iostream>
#include <random>

int main()
{
	using namespace std;

	LinkedList<double> IntList;	
	
	IntList.InsertAtFront(100);
	IntList.InsertAtEnd(200);
	IntList.InsertAtFront(50);
	IntList.PrintList();
	cout << boolalpha;
	cout << IntList.IsEmpty() << "\n";
	
	IntList.DeleteNode(100);
	IntList.PrintList();
	IntList.DeleteList();
	cout << IntList.IsEmpty() << "\n";

	return 0;
}

/*
	// Declare an array of pointers to Node<T> objects.
	const int size = 10;
	Node<int> *nodes[size];

	// For generating random integers
	std::random_device rd;
	std::mt19937 randNum(rd());

	// Create new Node<T> objects and set the pointers
	// in the array to point to those objects.
	for (int count = 0; count < size; ++count)
		nodes[count] = new Node<int>(randNum() % 100);

	// Print the value of each node
	for (int count = 0; count < size; ++count)
		std::cout << nodes[count]->GetData() << "\n";
	std::cout << std::endl;

	// Create an empty linked list
	LinkedList<int> List;

	// Print whether list is empty
	std::cout << std::boolalpha << List.IsEmpty() << "\n";

	// Insert the nodes into the linked list
	for (int count = 0; count < size; ++count)
		List.InsertAtEnd(nodes[count]);

	// Print whether list is empty
	std::cout << std::boolalpha << List.IsEmpty() << "\n";
	
	// Print list
	List.PrintList();

	// Delete some nodes and print list
	List.DeleteNode(nodes[1]->GetData());
	List.DeleteNode(nodes[5]->GetData());
	List.DeleteNode(nodes[size - 1]->GetData());
	List.PrintList();

	// Insert some nodes and print list
	Node<int> *n1 = new Node<int>(1000);
	Node<int> *n2 = new Node<int>(2000);
	Node<int> *n3 = new Node<int>(3000);
	List.InsertAtFront(n1);
	List.InsertAtEnd(n2);
	List.InsertAtFront(n3);
	List.PrintList();

	// Find some nodes and print their data
	Node<int> *pNode_1 = List.FindNode(nodes[7]->GetData());
	Node<int> *pNode_2 = List.FindNode(n2->GetData());
	std::cout << pNode_1->GetData() << "\n";
	std::cout << pNode_2->GetData() << "\n";
*/