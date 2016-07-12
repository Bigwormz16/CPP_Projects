#include <iostream>
#include <array>
#include <cstdlib>

template <typename T, int size>
class Stack
{
private:
	std::array<T, size> m_Stack;
	int m_top;

public:
	Stack()	// Creates an empty Stack
	{ m_top = -1; }

	void push(T value);
	T pop();
	bool isEmpty();
    void printStack();
};

template <typename T, int size>
void Stack<T, size>::push(T value)
{
	if (m_top >= size-1)
	{
		std::cerr << "Stack overflow!" << std::endl;
		return;
	}

	m_Stack[++m_top] = value;
}

template <typename T, int size>
T Stack<T, size>::pop()
{
	if (this->isEmpty())
	{
		std::cerr << "Stack empty!" << std::endl;
		exit(1);
	}

	return m_Stack[m_top--];
}

template <typename T, int size>
bool Stack<T, size>::isEmpty()
{
	if (m_top < 0)
		return true;
	else
		return false;
}

template <typename T, int size>
void Stack<T, size>::printStack()
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << m_Stack[i] << " (m_top = " << m_top << "),\t";
    }
    std::cout << "\n";
}

int main()
{
	Stack<char, 10> CharStack;
	CharStack.push('h');
	CharStack.push('s');
	CharStack.push('e');
	CharStack.push('k');
	CharStack.push('o');
	CharStack.push('L');

	while(!CharStack.isEmpty())
		std::cout << CharStack.pop() << " ";
	std::cout << std::endl;

	// CharStack.pop();	// prints "Stack empty!"

	return 0;
}
