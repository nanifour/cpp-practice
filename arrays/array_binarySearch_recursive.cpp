
#include <iostream>

using namespace std;

void recBinarySearch(const double list[], double targetValue,
                     int first, int last,
                     bool& found, int& loc);

int main()
{
    double list[] = {0.2, 1.3, 1.5, 2.7, 3.5, 4.4, 4.9, 5.2, 5.3, 5.8};

    double targetValue;            // to hold target value we search for
    bool isFound = false;   // flag indicating whether we found it
    int location = -1;       // index of target, if found

        cout << "Enter target value to search for: ";
        cin >> targetValue;

        isFound = false;

        recBinarySearch(list, targetValue, 0, 9, isFound, location);

        cout<<"\n\n";

        if( isFound)
            cout << targetValue << " found at array index: "
                 << location + 1 << "\n";
        else
            cout << targetValue << " not found in the list.\n";


    cout<<"\n\n";
    return 0;
}
///------------------------------------------------------------------
//                              array       target       range low      to high
void recBinarySearch(const double list[], double targetValue, int first, int last,
                     bool& found, int& loc) // flag and index of target value
{
    int middle;

    if (last >= first)              //if we have a list
    {
        middle = (first + last) / 2;   // look at the value in the 'middledle'

        if (list[middle] == targetValue)      // if that is it,
        {
            loc = middle;              // this is the index where we can find the target
            found = true;           // throw up the flag! We found it.

                                        // continuously divides list in half
        }                               // narrowing down our range of
        else if (list[middle] > targetValue)      // the array we half to examine to
            recBinarySearch(list, targetValue, first, middle - 1,     //bottom half
                            found, loc);
        else                                                // or
            recBinarySearch(list, targetValue, middle + 1, last,      // top half.
                            found, loc);                    //do it agin, agin
    }                                                       //till we find it
}
//=========================================================