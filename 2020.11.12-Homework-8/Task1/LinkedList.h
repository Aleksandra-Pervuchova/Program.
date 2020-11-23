#pragma once
#include<iostream>

struct Node {
public:
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) :data(data), next(next) {}
};


class LinkedList
{
private:
	//��������� �� ������ � ����� ������, ����� ������
	int count;
	Node* head;
	Node* tail;
public:
	//����������� �� ��������� � ����������� �����������
	LinkedList() : count(0), head(nullptr), tail(nullptr) {}
	LinkedList(const LinkedList& list);
	~LinkedList();
private:
	//indexValid(int);
	bool indexValid(int index);
public:
	//int length();
	int length();

	//bool addToHead(int);
	bool addToHead(int element);

	//bool addToTail(int);
	bool addToTail(int element);

	//bool add(int, int);
	bool add(int index, int element);

	//int get(int);
	int get(int index);

	//bool set(int, int);
	bool set(int index, int element);

	//operator[](int);
	int& operator[](int index);

	//operator<<(ostream&, const LinkedList);
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList list);

	//operator += (int);
	void operator+= (int element);

	/// <summary>
	/// ������� ������ ������
	/// </summary>
	/// <returns>�������� ��������, ��������� � ������</returns>
	int extractHead();

	/// <summary>
	/// ������� ����� ������
	/// </summary>
	/// <returns>�������� ��������, ��������� � �����</returns>
	int extractTail();

	/// <summary>
	/// ������� �������, ������� �� ����� index
	/// </summary>
	/// <returns>�������� ��������, ��������� �� ����� index</returns>
	int extract(int index);

	/// <summary>
	/// ������� �������
	/// </summary>
	/// <param name="">������ ���������� ��������</param>
	void operator-=(int);

	LinkedList& operator=(LinkedList);

	/// <summary>
	/// ����� ��������
	/// </summary>
	/// <param name="">�������� ��������</param>
	/// <returns>-1, ���� �������� � ������ ���</returns>
	int indexOf(int);

	/// <summary>
	/// ���������� �� ������� � ������. � ������� ����� �������� ����� �������
	/// </summary>
	/// <param name="">�������� ��������</param>
	bool contains(int);

	/// <summary>
	/// �������� ��� �������� �������.
	/// ������������ �������� ��������� ������.
	/// ����� ������ ������ �������� ����� next.
	/// </summary>
	/// <param name="">������ ������� ��������</param>
	/// <param name="">������ ������� ��������</param>
	/// <returns>false - ���� ������� ���� �����������</returns>
	bool swap(int, int);
};

