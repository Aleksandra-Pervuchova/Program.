#include <iostream>
#include <clocale>
#include <ctime>

using namespace std;

void printMenu()
{
    cout << "МЕНЮ" << endl;
    cout << "0 - Выход из программы" << endl;
    cout << "1 - Ввести несколько элемнетов с клавиатуры" << endl;
    cout << "2 - Добавить в массив n случайных чисел в промежутке от a до b(n, a, b вводится с клавиатуры)" << endl;
    cout << "3 - Вывести массив на экран" << endl;
    cout << "4 - Поиск индекса элемента" << endl;
    cout << "5 - Добавление массив к массиву" << endl;
    cout << "6 - Объединение массивов" << endl;
    cout << "7 - Вставка элемента в массив" << endl;
    cout << "8 - Удаление нескольких подряд идущих элементов массива" << endl;
    cout << "9 - Поиск подпоследовательности" << endl;
}

int* initArray(int capacity = 10)
{
    int* result = new int[capacity + 2]{ 0 };
    *(result + 1) = capacity;
    result += 2;
    return result;
}

void deleteArray(int* arr)
{
    delete[](arr - 2);
}

void expandArray(int*& arr)
{
    int* temp = initArray(2 * (*(arr - 1)));
    for (int i = 0; i < *(arr - 1); ++i)
    {
        *(temp + i) = *(arr + i);
    }
    *(temp - 2) = *(arr - 2);
    deleteArray(arr);
    arr = temp;
}

void addElement(int*& arr, int element)
{
    if (*(arr - 2) == *(arr - 1))
    {
        expandArray(arr);
    }
    *(arr + *(arr - 2)) = element;
    ++(*(arr - 2));

}


void addRandomElements(int*& arr, int n, int min, int max)
{
    for (int i = 0; i < n; ++i)
    {
        addElement(arr, rand() % (max - min + 1) + min);
    }
}

void printArray(int* arr)
{
    cout << "[" << *(arr - 2) << "/" << *(arr - 1) << "] {";
    for (int i = 0; i < *(arr - 2); ++i)
    {
        cout << *(arr + i) << (i == *(arr - 2) - 1 ? "}\n" : ", ");
    }
}

int search(int* arr, int element, int start = 0)
{
    int flag = 0;
    for (int i = start; i < *(arr - 2); ++i)
    {
        if (*(arr + i) == element)
        {
            return (start + i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return -1;
    }
}

void add(int*& arr, int* addedArr)
{
    for (int i = 0; i < *(addedArr - 2); ++i)
    {
        if (*(arr - 2) == *(arr - 1))
        {
            expandArray(arr);
        }
        *(arr + i + *(arr - 2)) = *(addedArr + i);
    }
    *(arr - 2) += *(addedArr - 2);
}

int* unify(int* a, int* b)
{
    int* result = new int[*(a - 2) + *(b - 2) + 2]{ 0 };
    *result = *(a - 2) + *(b - 2);
    *(result + 1) = *(a - 2) + *(b - 2);
    result += 2;
    if (*(a - 2) > * (b - 2))
    {
        for (int i = 0; i < *(b - 2); ++i)
        {
            *(result + i * 2) = *(a + i);
            *(result + i * 2 + 1) = *(b + i);
        }
        for (int i = 0; i < *(a - 2) - *(b - 2); ++i)
        {
            *(result + (*(b - 2)) * 2 + i) = *(a + *(b - 2) + i);
        }
    };
    if (*(b - 2) > * (a - 2))
    {
        for (int i = 0; i < *(a - 2); ++i)
        {
            *(result + i * 2) = *(a + i);
            *(result + i * 2 + 1) = *(b + i);
        }
        for (int i = 0; i < *(b - 2) - *(a - 2); ++i)
        {
            *(result + (*(a - 2)) * 2 + i) = *(b + *(a - 2) + i);
        }
    }
    return result;
}

int insert(int*& a, int index, int element)
{
    if (index < *(a - 2))
    {
        if (*(a - 2) == *(a - 1))
        {
            expandArray(a);
        }
        for (int i = *(a - 2); i > index; --i)
        {
            *(a + i) = *(a + i - 1);
        }
        *(a + index) = element;
        return 0;
    }
    else
    {
        return -1;
    }
}

int deleteGroup(int* a, int startIndex, int count)
{
    int k = 0;
    if ((startIndex + count) <= *(a - 2))
    {
        for (int i = startIndex + count; i < *(a - 2); ++i)
        {
            *(a + i - count) = *(a +i);
            ++k;
        }
        for (int i = *(a - 2) - count; i < *(a - 2); ++i)
        {
            *(a + i) = 0;
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int subSequence(int* a, int* b)
{
    int i = 0, j = 0;
    while (i < *(a - 2))
    {
        if (*(a + i) == *(b + j))
        {
            ++j;
            if (j == *(b - 2))
            {
                return i - *(b - 2) + 1;
            }
        }
        else
        {
            j = 0;
        }
        ++i;
    }
    return -1;
}



void processChoice(int*& arr1, int*& arr2, int choice)
{
    switch (choice)
    {
    case 1:
    {
        cout << "С каким массивом работаем (1 / 2) ? ";
        int y = 0;
        cin >> y;
        cout << "Количество = ";
        int k = 0;
        cin >> k;
        int x = 0;
        for (int i = 0; i < k; ++i)
        {
            cin >> x;
            addElement((y == 1 ? arr1 : arr2), x);
        }
    }
    break;
    case 2:
    {
        cout << "С каким массивом работаем (1 / 2) ? ";
        int a = 0;
        cin >> a;
        cout << "Количество = ";
        int n = 0;
        cin >> n;
        cout << "Min = ";
        int min = 0;
        cin >> min;
        cout << "Max = ";
        int max = 0;
        cin >> max;
        addRandomElements((a == 1 ? arr1 : arr2), n, min, max);
    }
    break;
    case 3:
    {
        cout << "С каким массивом работаем (1 / 2) ? ";
        int t = 0;
        cin >> t;
        printArray((t == 1 ? arr1 : arr2));
    }
    break;
    case 4:
    {
        cout << "С каким массивом работаем (1 / 2) ? ";
        int s = 0;
        cin >> s;
        cout << "Искомый элемент = ";
        int z = 0;
        cin >> z;
        cout << search((s == 1 ? arr1 : arr2), z, 0);
    }
    break;
    case 5:
    {
        cout << "Какой массив добавляем (1 / 2) ? ";
        int a = 0;
        cin >> a;
        add((a == 1 ? arr2 : arr1), (a == 1 ? arr1 : arr2));
    }
    break; 
    case 6:
    {
        int* unifyArr = unify(arr1, arr2);
        printArray(unifyArr);
        deleteArray(unifyArr);
    }
    break;
    case 7:
    {
        cout << "С каким массивом работаем (1 / 2) ? ";
        int a = 0;
        cin >> a;
        cout << "Индекс вставляемого элемента = ";
        int i = 0;
        cin >> i;
        cout << "Значение вставляемого элемента = ";
        int x = 0;
        cin >> x;
        insert((a == 1 ? arr1 : arr2), i, x);
    }
    break;
    case 8:
    {
        cout << "С каким массивом работаем (1 / 2) ? ";
        int a = 0;
        cin >> a;
        cout << "Индекс начального элемента удаляемой последовательности = ";
        int i = 0;
        cin >> i;
        cout << "Количество удаляемых элементов = ";
        int k = 0;
        cin >> k;
        deleteGroup((a == 1 ? arr1 : arr2), i, k);
    }
    break;
    case 9:
    {
        cout << "Массив, в котором ищем подпоследовательность ";
        int a = 0;
        cin >> a;
        cout << subSequence((a == 1 ? arr1 : arr2), (a == 1 ? arr2 : arr1)) << endl;
    }
    break; 
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int* a = initArray(10);
    int* b = initArray(10);

    int choice = 0;
    do
    {
        system("cls");
        printMenu();
        cin >> choice;
        processChoice(a, b, choice);
        system("pause");
    } while (choice != 0);

    deleteArray(a);
    deleteArray(b);
    return EXIT_SUCCESS;
}
