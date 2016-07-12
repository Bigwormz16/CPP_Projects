#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
struct Element
{
	T data;
	Element<T> *next;
};

template <typename T>
class Stack
{
private:
	Element<T> *m_top;

public:
	Stack();   // create an empty stack
    void push(T value);
    T pop();
    T top();
    bool isEmpty();
};

template <typename T>
Stack<T>::Stack()
: m_top{nullptr}
{
}

template <typename T>
void Stack<T>::push(T value)
{
    Element<T> *newElem = new (std::nothrow) Element<T>;
    if (newElem == nullptr)
    {
        std::cerr << "push(): Could not allocate memory for new element!" << std::endl;
        return;
    }
    newElem->data = value;
    newElem->next = m_top;
    m_top = newElem;
}

template <typename T>
T Stack<T>::pop()
{
    if (this->isEmpty())
    {
        std::cerr << "Stack empty!" << std::endl;
        throw std::logic_error("Calling top() when stack is empty is illegal!");
    }
    else
    {
        Element<T> *newTop = m_top->next;
        T value = m_top->data;
        delete m_top;
        m_top = newTop;
        return value;
    }
}

template <typename T>
T Stack<T>::top()
{
    if (this->isEmpty())
    {
        std::cerr << "Stack empty!" << std::endl;
        throw std::logic_error("Calling top() when stack is empty is illegal!");
    }
    else
    {
        return m_top->data;
    }
}

template <typename T>
bool Stack<T>::isEmpty()
{
    if (m_top == nullptr)
        return true;
    else
        return false;
}


int main()
{
    using namespace std;

    Stack<string> Message;

    cout << boolalpha << Message.isEmpty() << "\n";
    Message.push("awesome!");
    Message.push("is ");
    Message.push("Linux ");
    cout << Message.isEmpty() << "\n";

    cout << "Message: \n\"";
    for (int i = 0; i < 3; ++i)
    {
        cout << Message.pop();
    }
    cout << "\"\n";
    cout << Message.isEmpty() << "\n";

    return 0;
}
