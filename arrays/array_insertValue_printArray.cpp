

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 20;

void insertAt(int list[], int& len, int insertItem, int index);

void print(const int list[], int len);

int main()
{
    int list[ARRAY_SIZE] = {4, 33, 25, 68, 50, 30, 63,
                            47, 54, 86, 82, 71};

    int length = 12;

    int item, index;

    print(list, length);

    cout << "Enter the item to be inserted and its position."
         << endl
         << "(Position of the first element is 0): ";
    cin >> item >> index;
    cout << endl;

    if (length == ARRAY_SIZE)
        cout << "Cannot insert in a full list." << endl;
    else
        insertAt(list, length, item, index);

    print(list, length);

    return 0;
}

void insertAt(int list[], int& len, int insertItem, int index)
{
    if (index < 0 || index > ARRAY_SIZE)
    {
        cout << "Position of the item to be inserted is out of range."
             << endl;
        if (index < 0)
            cout << "Position of the item to be inserted must "
                 << "be nonnegative." << endl;
        else
            cout << "The size of the list is " << ARRAY_SIZE << endl;
    }
    else
    {
        if (index > len)
        {
            cout << "Item will be inserted at the end of the list "
                 << "at position " << len << endl;
            list[len] = insertItem;
            len++;
        }
        else
        {
            for (int i = len - 1; i >= index; i--)
                list[i + 1] = list[i];

            list[index] = insertItem;
            len++;
        }
    }
}

void print(const int list[], int len)
{
    for (int i = 0; i < len; i++)
        cout << list[i] << " ";
    cout << endl;
}