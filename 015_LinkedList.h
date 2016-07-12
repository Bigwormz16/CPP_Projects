#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "015_Node.h"
#include <iostream>

template <typename T>
class LinkedList
{
public:
	Node<T> *head;

	// Constructor : creates an empty list
	LinkedList();

	// Public interface:
	void InsertAtFront(T data);
	void InsertAtEnd(T data);
	Node<T>* FindNode(T data);	// @return: null - if node not found
	void DeleteNode(T data);

	bool IsEmpty();
	void PrintList();
	void DeleteList();
};

template <typename T>
LinkedList<T>::LinkedList() : head{nullptr}
{
}

template <typename T>
void LinkedList<T>::InsertAtFront(T data)
{
	Node<T> *node = new Node<T>(data);
	// Not checking for std::bad_alloc exception because
	// this function cannot do anything to free some memory.
	// Even if it can, it would be unreasonable and too complicated
	// because it is just a member function of an object.

	node->SetNext(head);
	head = node;
}

template <typename T>
void LinkedList<T>::InsertAtEnd(T data)
{
	Node<T> *node = new Node<T>(data);
	// Not checking for std::bad_alloc exception because
	// this function cannot do anything to free some memory.
	// Even if it can, it would be unreasonable and too complicated
	// because it is just a member function of an object.

	Node<T> *crawler = head;
	if (this->IsEmpty())
	{
		head = node;
		return;
	}
	while(crawler->GetNext() != nullptr)
	{
		crawler = crawler->GetNext();
	}
	crawler->SetNext(node);
}

template <typename T>
Node<T>* LinkedList<T>::FindNode(T data)
{
	Node<T> *node = head;
	while(node != nullptr && node->GetData() != data)
		node = node->GetNext();

	if (node == nullptr)
		std::cout << "Node not found!" << std::endl;

	return node;	// returns nullptr if not found
}

// If the linked list contains duplicate copies of data, this function
// will delete the first occurence of the node containing the data.
template <typename T>
void LinkedList<T>::DeleteNode(T data)
{
	Node<T> *node = FindNode(data);

	if (node == nullptr)
	{
		std::cout << "Node does not exist in the list!" << std::endl;
		return;
	}

	if (node == head)
		head = head->GetNext();
	else
	{
		Node<T> *prevNode = head;
		while (prevNode->GetNext() != node)
			prevNode = prevNode->GetNext();

		prevNode->SetNext(node->GetNext());
	}

	delete node;
	std::cout << "Node successfully deleted!" << std::endl;
}

template <typename T>
bool LinkedList<T>::IsEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

template <typename T>
void LinkedList<T>::PrintList()
{
	if (this->IsEmpty())
	{
		std::cout << "List is empty!" << std::endl;
		return;
	}

	Node<T> *temp = head;
	while(temp != nullptr)
	{
		std::cout << temp->GetData() << "\n";
		temp = temp->GetNext();
	}
	std::cout << std::endl;
}

// Recursive version cannot be implemented in this implementation
// of the LinkedList class because it will take a node pointer as
// argument and the first call to it will take head pointer of the list.
template <typename T>
void LinkedList<T>::DeleteList()
{
	if (this->IsEmpty())
	{
		std::cout << "List is already empty!" << std::endl;
		return;
	}

	Node<T> *crawler = head;
	while (crawler->GetNext() != nullptr)
	{
		Node<T> *next = crawler->GetNext();
		delete crawler;
		crawler = next;
	}
	if (crawler != nullptr)
	{
		delete crawler;
	}

	head = nullptr;
}

#endif
