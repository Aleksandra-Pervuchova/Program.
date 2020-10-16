#pragma once
#include<iostream>

using namespace std;

struct ArrayList 
{
	int count;
	int capacity;
	int* data;

	ArrayList(); 
	ArrayList(int cap); 

	~ArrayList();

	
	bool add(int element);

	
	bool add(int index, int element);

	
	bool add(ArrayList& list);

	
	bool addAll(int index, ArrayList& list);

	
	int indexOf(int element);

	
	void print();

	
	bool remove(int index);

};
