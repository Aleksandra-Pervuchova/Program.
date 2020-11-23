#include<iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList list1;
	cout << "list1: " << list1 << endl;
	cout << "list[3] = " << list1.get(3) << endl;
	list1.addToHead(45);
	cout << "list1: " << list1 << endl;
	list1.extractHead();
	cout << "list1: " << list1 << endl;
	list1.addToTail(54);
	cout << "list1: " << list1 << endl;
	list1.extractTail();
	cout << "list1: " << list1 << endl;
	list1.add(405, 504);
	cout << "list1: " << list1 << endl;
    list1[405] = 504;
	cout << "list1: " << list1 << endl;
	list1.extract(0);
	list1 += 9;
	cout << "list1: " << list1 << endl;
	list1 -= 0;
	cout << "list1: " << list1 << endl;

	list1.addToHead(4);
	cout << "list1: " << list1 << endl;
    list1 += 5;
	cout << "list1: " << list1 << endl;

	LinkedList list2;
	cout << "list2: " << list2 << endl;
	list2 = list1;
	cout << "list2: " << list2 << endl;
	list2.add(1, 0);
	cout << "list2: " << list2 << endl;
	list2[3] = 0;
	cout << "list2: " << list2 << endl;
	list2.addToTail(4);
	cout << "list2: " << list2 << endl;
	list2.extractHead();
	cout << "list2: " << list2 << endl;
	list2.addToHead(4);
	cout << "list2: " << list2 << endl;
	list2.extractTail();
	cout << "list2: " << list2 << endl;
	list2[2] = 4;
	cout << "list2: " << list2 << endl;
	list1 = list2;
	cout << "list1: " << list1 << endl;

	return 0;
}





/*продемонстрировать работу всех функций
показать, что все функции и операторы корректно работают:
1). С пустым списком.
2). Со списком из 1 элемента.
3). Со списком из нескольких элементов.
*/
