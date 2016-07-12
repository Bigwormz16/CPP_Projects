#include "test_15_Node.h"

template <typename T>
class CircularLinkedList
{
public:
	Node<T> *head;

	CircularLinkedList();
	void PrintList();
	Node<T>* FindNode(T data);	// returns null if no matching node found
	// FindNode(Node<T> *node);
    void InsertAtFront(Node<T> *node);
    void InsertAtEnd(Node<T> *node);
    void DeleteNode(T data);
	// void DeleteNode(Node<T> *node);
};

/*template <typename T>
CircularLinkedList<T>::CircularLinkedList() : head{nullptr}
{
}

template <typename T>
void CircularLinkedList<T>::InsertAtFront(Node<T> *node)
{
	if (node == nullptr)
	{
        std::cout << "InsertAtFront(): Invalid argument - " <<
			"node is null !" << std::endl;
		return;
	}
	node->SetNext(head);
	head = node;
}*/