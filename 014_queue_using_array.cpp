#include <iostream>
#include <array>

enum class Error
{
	QUEUE_FULL,
	QUEUE_EMPTY
};

template <typename T, int size>
class Queue
{
private:
	std::array<T, size> m_Queue;
	int m_front;
	int m_rear;

public:
	Queue() : m_front{0}, m_rear{0}	// default constructor
	{	}

	// Public Interface:
	void Enqueue(T value);
	T Dequeue();
	const T& Peek();
	void ShowQueue();
};

template <typename T, int size>
void Queue<T, size>::Enqueue(T value)
{
	if (m_rear >= size)
		throw Error::QUEUE_FULL;

	m_Queue.at(m_rear++) = value;
}

template <typename T, int size>
T Queue<T, size>::Dequeue()
{
	if (m_rear <= m_front)
		throw Error::QUEUE_EMPTY;

	T temp = m_Queue.at(m_front);

	// Move all elements one step forward and decrement m_rear
	for (int count = m_front; count < m_rear - 1; ++count)
		m_Queue.at(count) = m_Queue.at(count + 1);
	--m_rear;

	return temp;
}

template <typename T, int size>
const T& Queue<T, size>::Peek()
{
	if (m_rear > m_front)	// there is at least one element
		return m_Queue.at(m_front);
	else
		throw Error::QUEUE_EMPTY;
}

template <typename T, int size>
void Queue<T, size>::ShowQueue()
{
	if (m_rear > m_front)	// there is at least one element
	{
		for (int count = m_front; count < m_rear; ++count)
			std::cout << m_Queue.at(count) << " ";
		std::cout << std::endl;
	}
	else
		throw Error::QUEUE_EMPTY;
}

int main()
{
	const int size = 10;
	Queue<int, size> IntQueue;
	try
	{
		// Fill queue with integers
		for (int count = 0; count < size; ++count)
			IntQueue.Enqueue(count + 1);

		// Print queue
		IntQueue.ShowQueue();

		// Remove some elements and print queue
		for (int count = 0; count < 3; ++count)
			IntQueue.Dequeue();	// discard the returned value
		IntQueue.ShowQueue();

		// Add some new elements and print queue
		for (int count = 0; count < 3; ++count)
			IntQueue.Enqueue(20 + count);
		IntQueue.ShowQueue();
	}
	catch (Error Err)
	{
		if (Err == Error::QUEUE_FULL)
		{
			std::cerr << "Queue full!" << std::endl;
			return 1;
		}

		if (Err == Error::QUEUE_EMPTY)
		{
			std::cerr << "Queue empty!" << std::endl;
			return 1;
		}
	}

	return 0;
}
