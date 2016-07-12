#include <iostream>
#include <stdexcept>

template <typename T>
struct Node
{
	T data;
	Node<T> *prev;
	Node<T> *next;
};

template <typename T>
class Queue
{
private:
	Node<T> *m_head;
	Node<T> *m_tail;

public:
	Queue() : m_head{nullptr}, m_tail{nullptr}
	{   }

	void enqueue(T data)
	{
		Node<T> *newElem = new (std::nothrow) Node<T>;
        if (newElem == nullptr)
        {
            std::cerr << "enqueue(): Error - cannot allocate memory for new element!" << std::endl;
            return;
        }

		newElem->data = data;
        newElem->prev = m_tail;
        newElem->next = nullptr;

        if (m_head == nullptr)
        {
            m_head = newElem;
        }

        if (m_tail != nullptr)
        {
            m_tail->next = newElem;
        }
        m_tail = newElem;
	}

    void dequeue()
    {
        if (this->isEmpty())
        {
            std::cerr << "Illegal operation: dequeue() when queue is empty!" << std::endl;
            return;
        }

        Node<T> *temp = m_head;
        if (m_head->next != nullptr)
        {
            m_head = m_head->next;
            m_head->prev = nullptr;
        }
        else
        {
            m_head = nullptr;
            m_tail = nullptr;
        }
        delete temp;
    }

    T& front()
    {
        if (this->isEmpty())
        {
            throw std::logic_error("Queue is empty!");
        }

        return m_head->data;
    }

    bool isEmpty() { return m_head == nullptr; }
};

int main()
{
    using namespace std;

    Queue<int> IntQ;
    IntQ.enqueue(10);
    IntQ.enqueue(20);
    IntQ.enqueue(30);
    cout << IntQ.front() << "\n";
    cout << boolalpha << "Queue Empty? : " << (IntQ.isEmpty() ? "Yes" : "No") << "\n";
    IntQ.dequeue();
    cout << IntQ.front() << endl;

    return 0;
}
