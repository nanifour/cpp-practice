
/// function removes all items of that value from array

#include <iostream>

using namespace std;

void removeAll(int list[], int& len, int removeItem);
void print(const int list[], int len);

int main()
{
	int list[20] = {4, 7, 4, 4, 4, 3, 4, 4, 4, 8, 4, 4};

	int length = 12;

	int item;

	print(list, length);

	cout << "Enter the item to be removed: ";
	cin >> item;
	cout << endl;

	removeAll(list, length, item);

    cout << "List after removing " << item << endl;

	print(list, length);

	return 0;
}

void removeAll(int list[], int& len, int removeItem)
{
	int i, j;

	bool found = false;

	if (len == 0)
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		i = 0;
		while (i < len)
		{
			if (removeItem == list[i])
			{
				found = true;

				for (j = i; j < len; j++)
					list[j] = list[j + 1];

				len--;
			}
			else
				i++;
		}

		if (!found)
			cout << removeItem << " is not in the list." << endl;
	}
}

void print(const int list[], int len)
{
	for (int i = 0; i < len; i++)
		cout << list[i] << " ";
	cout << endl;
}