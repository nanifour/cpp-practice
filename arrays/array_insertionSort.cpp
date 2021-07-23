
// driver for insertion sort function with an
// array of integers

#include <iostream>

using namespace std;

void insertionSort(int list[], int listLength);

int main()
{
    int list[] = {2, 56, 34, 25, 73, 46, 89, 10, 5, 16};  
    int i;                                                

    insertionSort(list, 10);                              

    cout << "After sorting, the list elements are:"
         << endl;                                         

    for (i = 0; i < 10; i++)                              
        cout << list[i] << " ";                           

    cout << endl;                                         

    return 0;                                             
}

void insertionSort(int list[], int listLength)
{
    int firstOutOfOrder, location;
    int temp;

    for (firstOutOfOrder = 1; firstOutOfOrder < listLength;
                              firstOutOfOrder++)
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            temp = list[firstOutOfOrder];
            location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;
            }
            while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
} //end insertionSort
