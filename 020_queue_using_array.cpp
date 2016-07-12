#include <iostream>
#include <array>

template <typename T, const int size>
class Queue
{
private:
    std::array<T, size> m_que;
    // head is m_que[0]
    unsigned int tail;   // Holds index at which an element is to be inserted.

    // Only used internally within the class.
    inline bool isFull()
    {
        return (tail >= m_que.size());
    }

public:
    Queue() : tail{0} {}

    void enqueue(T data)
    {
        if (this->isFull())
        {
            std::cerr << "Cannot enqueue as queue is full! " <<
                "Dequeue something first and then use Enqueue()."<< std::endl;
        }

        m_que[tail++] = data;
    }

    // Expensive operation. O(n) complexity.
    void dequeue()
    {
        if (this->isEmpty())
        {
            std::cerr << "Illegal operation: dequeue() when queue is empty!" << std::endl;
            return;
        }

        for (unsigned int i = 0; i < tail-1; ++i)
        {
            m_que[i] = m_que[i+1];
        }
        --tail;
    }

    T& front()
    {
        if (this->isEmpty())
        {
            std::cerr << "Queue is empty!" <<
                "Front of queue will contain  garbage value!" << std::endl;
        }
        return m_que[0];
    }

    bool isEmpty() { return (tail <= 0); }
};


int main()
{
    using namespace std;

    Queue<int, 10> IntQ;
    IntQ.enqueue(10);
    IntQ.enqueue(20);
    IntQ.enqueue(30);
    cout << IntQ.front() << "\n";
    cout << boolalpha << "Queue Empty? : " << (IntQ.isEmpty() ? "Yes" : "No") << "\n";
    IntQ.dequeue();
    cout << IntQ.front() << endl;

    return 0;
}
