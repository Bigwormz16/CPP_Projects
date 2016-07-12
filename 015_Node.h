#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
	T data;
	Node<T> *next;

public:
	Node() : next{nullptr}	{ }
	Node(T value) : data{value}, next{nullptr}	{ }

	// Public interface:
	T		 GetData() const 		{ return data; }	// Read only - const function
	Node<T>* GetNext() const 		{ return next; }	// Read only - const function
	void 	 SetData(T value) 		{ data = value; }
	void	 SetNext(Node<T> *node) { next = node; }
};

#endif