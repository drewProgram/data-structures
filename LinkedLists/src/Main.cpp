#include <iostream>

/**
 * It works similar like an array, but for getting
 * a value you need to pass through all the nodes.
 * 
 * Disadvantage: Slow to get Nth element.
 * Advantage: Insertions and deletions can be very quick.
 * 
 * There's also the doubly linked list, which references the
 * previous node of the list, not only the next, which could be very
 * handy for certain operations.
 */

struct Node
{
	int data;
	Node* next;
};

// Simple Linked List
class LinkedList
{
private:
	Node* m_Head;
	Node* m_Tail;

public:
	LinkedList()
		: m_Head(nullptr), m_Tail(nullptr) {}

	void Init(int value)
	{
		Node* temp = new Node();
		temp->data = value;
		temp->next = nullptr;

		if (m_Head == nullptr)
		{
			m_Head = temp;
			m_Tail = temp;

			return;
		}

		m_Tail->next = temp;
		m_Tail = temp;
	}

	void PrintList()
	{
		Node* current = m_Head;

		while (current != nullptr)
		{
			std::cout << current->data << std::endl;
			current = current->next;
		}
	}

	void Push(int value)
	{
		Node* newNode = new Node();

		newNode->data = value;
		newNode->next = m_Head;

		m_Head = newNode;
	}

	void PushBack(int value)
	{
		Node* temp = new Node();
		temp->data = value;
		temp->next = nullptr;

		m_Tail->next = temp;
		m_Tail = temp;
	}

	void PushAtPosition(int position, int value)
	{
		Node* previous = new Node();
		Node* current = new Node();
		Node* temp = new Node();

		current = m_Head;

		for (int i = 1; i < position; i++)
		{
			previous = current;
			current = current->next;
		}

		temp->data = value;
		previous->next = temp;
		temp->next = current;
	}

	int Pop()
	{
		int removedValue = 0;
		Node* nextNode = nullptr;

		nextNode = m_Head->next;
		removedValue = m_Head->data;
		delete m_Head;

		m_Head = nextNode;

		return removedValue;
	}

	int RemoveLast()
	{
		int removedValue = 0;
		/**
		 * If there is only one item in the list, remove it
		 */
		if (m_Head->next == nullptr)
		{
			removedValue = m_Head->data;
			delete m_Head;

			return removedValue;
		}

		/**
		 * Get to the second to last node in the list
		 */
		Node* current = m_Head;
		while (current->next->next != nullptr)
			current = current->next;

		/**
		 * Now current points to the second to last item of the
		 * list, so let's remove current->next
		 */
		removedValue = current->next->data;
		delete current->next;
		current->next = nullptr;

		return removedValue;
	}

	int RemoveByIndex(int index)
	{
		int i = 0;
		int removedValue = -1;
		Node* current = m_Head;
		Node* temp = nullptr;

		if (index == 0)
			return Pop();

		for (i = 0; i < index - 1; i++)
		{
			if (current->next == nullptr)
				return -1;
		}

		temp = current->next;
		removedValue = temp->data;
		current->next = temp->next;
		delete temp;

		return removedValue;
	}
};

int main()
{
	std::cout << "Linked Lists!" << std::endl;

	std::cin.get();
}