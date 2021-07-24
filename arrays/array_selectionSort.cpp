
#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 10;

void selectionSort(string list[], int length);

int main()
{
	string nameList[ARRAY_SIZE];
	string name;
	int index;

    cout << "Enter " << ARRAY_SIZE << " strings." << endl;

	for (index  = 0; index < ARRAY_SIZE; index++)
		cin >> nameList[index];

	cout << endl;

	   //sort the list
	selectionSort(nameList, ARRAY_SIZE);

    cout << "List after sorting: ";

	for (index  = 0; index < ARRAY_SIZE; index++)
		cout << nameList[index] << " ";
    cout << endl;

	return 0;
}

void selectionSort(string list[], int length)
{
    string temp;
    int index;
    int smallestIndex;
    int minIndex;

    for (index = 0; index < length - 1; index++)
    {
        smallestIndex = index;

        for (minIndex = index + 1; minIndex < length; minIndex++)
            if (list[minIndex] < list[smallestIndex])
                smallestIndex = minIndex;

        temp = list[smallestIndex];
        list[smallestIndex] = list[index];
        list[index] = temp;
    }
}
