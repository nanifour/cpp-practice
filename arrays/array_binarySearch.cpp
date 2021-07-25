//Driver for the binary search function

#include <iostream>

using namespace std;

void info();    //info about this program

                    //array          size of array       target value
int binarySearch(const double list[], int listLength, double targetValue);

int main()
{
    cout << "\n\n";
    info();

    double list[] = {0.1, 2.6, 3.2, 4.5, 4.9, 5.5, 5.8, 5.9, 6, 7.8};  //Line 1


    cout <<"\n\n Test_1 of value 4.5 = "<< binarySearch(list, 10, 4.5);   //see what the value actually returns
    if(binarySearch(list, 10, 4.5)>=0)        //now call it with an if/else for output
    cout <<"\n\n Target value found at index["<<binarySearch(list,10,4.5)<<"]\n";
    else
    cout <<"\n\n  Target NOT found in the list.\n";
    cout <<"\n\n-------------------------------------------";

                                        /// search for a value NOT in list
    cout <<"\n\n\n Test2 of value 2.5 = "<< binarySearch(list, 10, 2.5);   //see what the value actually returns
    if(binarySearch(list, 10, 2.5) > 0)        //now call it with an if/else for output
    cout <<"\n\nTarget value found!";
    else
    cout <<"\n\nTarget NOT found in the list.\n";
    cout <<"\n\n-------------------------------------------";



    cout<<"\n\n";
    return 0;   //end of main function
}//========================================================

int binarySearch(const double list[], int listLength, double targetValue)
{
    int first = 0, middle=0 ;
    int last = listLength - 1;
    bool found = false;

    while (first <= last && !found)      //if not done, and havnt found it
    {
        middle = (first + last) / 2;     //cut the list in half

        if (list[mid] == targetValue)    // if that is it,
            found = true;               // throw up the flag! We found it.
        else if (list[mid] > targetValue) // otherwise, we compare
            last = mid - 1;             // to see if it's in the upper half
        else
            first = mid + 1;            // or in the the lower half
    }

    if (found)                  // if the flag is up, we found it and
        return mid;             // we return the index where its located
    else
        return -1;              //otherwise we didnt' so return -1
}//end binarySearch

//=========================================================
void info(){
cout <<"\nBINARY SEARCH - searches for a target value in the array.\n"
    <<"Pre-Condition: Values in array must be sorted before calling\n"
    <<" this function. Call bubble sort or selection sort beforehand.\n"
    <<" If the function finds the target value, the array\n"
    <<" index number for that value is returned. Otherwise,\n"
    <<"  a value of -1 is returned.\nAlgorithm begins by choosing"
    <<" a middle value in the list\n and comparing it to the specified"
    <<" target value.\nEach comparison allows us to narrow the target\n"
    <<" range by dividing the list in half.\n"
    <<"\n----------------------------------------------------\n\n";
}
//=========================================================
//=========================================================

