int* initArray(int capacity = 10)
{
    int* result = new int[capacity + 2]{ 0 };
    *(result + 1) = capacity;
    result += 2;
    return result;
}