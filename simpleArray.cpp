// Arrays 

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//global variable
const int ARRAY_SIZE = 10;

//call function
void printit ( int  list [],  int size );

int main()
{


    int list [ARRAY_SIZE];
    int looper;
    int i;



      // Assign 0 to each component of list
      for (looper = 0;looper< ARRAY_SIZE ;looper++)
           list [looper] = 0 ;

     // Assign some values to the array

     list [5] = 34;
     list [3] = 63;

     printit ( list,  ARRAY_SIZE );

     i = 4;
     list [2 * i -3] = 58 ;
     list [3] = 10;

     printit ( list,  ARRAY_SIZE );

     list [6] = 35;

     printit ( list,  ARRAY_SIZE );

     list[9] = list [3] + list [6];
     //NOT list [9] = 3 + 6 ;


     list[0] = 2 * list[3];

    //list [5000] = 7; //????? there is not index 5000!

     printit ( list,  ARRAY_SIZE );


     cout << "\n\nprinting in reverse order \n\n";
     for (looper = ARRAY_SIZE -1;looper >=0;looper--)
         cout << list [looper]<<endl;


     cout <<"\nExtra print\n";
     cout << "list = " << list << endl ;

     cout << endl<< endl;


   return 0;
}
// prints out the entries in the array list
//size tells the number of components
void printit ( int  list [],  int size )
{
     int looper ;

     cout << "\nthe array \n\n";
      for (looper = 0;looper< size;looper++)

            cout << "list [" << looper << "] = "
                 << list [looper] << endl;

}
