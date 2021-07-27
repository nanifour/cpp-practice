//Driver for bubble sort function

#include <iostream>

using namespace std;

void info();
void bubbleSort(double list[],  int length);

int main()
{
    cout << "\n\n";
    info();

    double list[] = {6.1, 2.6, 1.2, 4.5, 2.9, 1.5, 5.8, 4.7, 5, 6.8};  

    bubbleSort(list, 10);                                 

    cout << "List Values Sorted:\n";                      
    for (int index = 0; index < 10; index++)                              
        cout << list[index] << "  ";                           


    cout<<"\n\n";
    return 0;   //end of main function
}//========================================================
void bubbleSort(double list[], int length){

    double temporary=0;         /// a place to hold a value when swapping
    int iteration=0, index=0;

    for (iteration = 1; iteration < length; iteration++)
    {
        for (index = 0; index < length - iteration; index++)

            if (list[index] > list[index + 1])
            {
                temporary = list[index];
                list[index] = list[index + 1];  /// this is the swap part
                list[index + 1] = temporary;
            }
    }
}
//=========================================================
void info(){
cout <<"\n -bubble sort is a simple sorting algorithm\n that repeatedly steps through"
    <<" the list to be\n sorted, comparing each pair of adjacent\n"
    <<" values & swapping them if theyre in the wrong order.\n"
    <<"----------------------------------------------------\n\n";
}
//=========================================================
//=========================================================

