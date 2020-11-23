#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
	tail = head = nullptr;
	count = 0;

	Node* temp = list.head;
	while (temp != nullptr)
	{
		addToTail(temp->data);
		temp = temp->next;
	}
}

LinkedList::~LinkedList()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* node = temp;
		temp = temp->next;
		delete node;
	}
}

bool LinkedList::indexValid(int index)
{
	return index >= 0 && index < count;
}

int LinkedList::length()
{
	return count;
}

bool LinkedList::addToHead(int element)
{
	if (head == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		head = new Node(element, head);
	}
	++count;
	return true;
}

bool LinkedList::addToTail(int element)
{
	if (tail == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		tail->next = new Node(element);
		tail = tail->next;
	}
	++count;
	return true;
}

bool LinkedList::add(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		return addToHead(index);
	}
	if (index == count)
	{
		return addToTail(index);
	}
	Node* temp = head;
	while (index > 1)
	{
		temp = temp->next;
		--index;
	}
	temp->next = new Node(element, temp->next);
	++count;
	return true;
}

int LinkedList::get(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		return head->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}
	Node* temp = head;
	while (index > 0)
	{
		temp = temp->next;
		--index;
	}
	return temp->data;
}

bool LinkedList::set(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		head->data = element;
	}
	else if (index == count - 1)
	{
		tail->data = element;
	}
	else
	{
		Node* temp = head;
		while (index > 0)
		{
			temp = temp->next;
			--index;
		}
		temp->data = element;
	}
	return true;
}

int& LinkedList::operator[](int index)
{
	if (head == nullptr)
	{
		addToHead(0);
		return head->data;
	}
	if (index <= 0)
	{
		return head->data;
	}
	if (index >= count)
	{
		addToTail(0);
		return tail->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}
	Node* temp = head;
	while (index > 0)
	{
		temp = temp->next;
		--index;
	}
	return temp->data;
}

void LinkedList::operator+=(int element)
{
	addToTail(element);
}

int LinkedList::extractHead()
{
	if (head == nullptr)
	{
		return -1;
	}
	int result = head->data;
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		--count;
		return result;
	}
	Node* node = head->next;
	delete head;
	head = node;
	--count;
	return result;
}

int LinkedList::extractTail()
{
	if (head == nullptr)
	{
		return -1;
	}
	int result = tail->data;
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		--count;
		return result;
	}
	Node* node = head;
	while (node->next != nullptr && node->next->next != nullptr)
	{
		node = node->next;
	}
	delete node->next;
	tail = node;
	tail->next = nullptr;
	--count;
	return result;
}

int LinkedList::extract(int index)
{
	if (head == nullptr || !(indexValid(index)))
	{
		return -1;
	}
	if (index == 0)
	{
		return extractHead();
	}
	if (index == count - 1)
	{
		return extractTail();
	}
	Node* node = head;
	int num = 0;
	while (num != index - 1)
	{
		node = node->next;
		++num;
	}
	Node* temp = node->next;
	int result = temp->data;
	node->next = node->next->next;
	delete temp;
	--count;
	return result;
}

void LinkedList::operator-=(int index)
{
	extract(index);
}

LinkedList& LinkedList::operator=(LinkedList list)
{
	Node* temp1 = head;
	for (int i = 0; i < count; ++i)
	{
		Node* node = temp1;
		temp1 = temp1->next;
		delete node;
	}
	Node* temp2 = list.head;
	while (temp2 != nullptr)
	{
		addToTail(temp2->data);
		temp2 = temp2->next;
	}

	return *this;
}

int LinkedList::indexOf(int element)
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* node = head;
	int index = 0;
	while (node != nullptr)
	{
		if (node->data == element)
		{
			return index;
		}
		node = node->next;
		++index;
	}
	return -1;
}

bool LinkedList::contains(int element)
{
	return ((indexOf(element) != -1) ? true : false);
}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
	stream << "[" << list.count << "]{";
	if (list.head == nullptr)
	{
		stream << "EMPTY";
	}
	else
	{
		Node* temp = list.head;
		while (temp != nullptr)
		{
			stream << temp->data;
			if (temp->next != nullptr)
			{
				stream << ", ";
			}
			temp = temp->next; //ïåðåõîäèì íà ñëåäóþùèé ýëåìåíò
		}
	}
	stream << "}";

	return stream;
}

