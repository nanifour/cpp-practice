#include <iostream>     
#include <fstream>      
#include <iomanip>      
#include <cmath>        
#include <string>

using namespace std;

 int menu();
 void radiusSurfArea2(float,float);
 double reciprocal( double value);
 void disply_cslogin_Info();

const double PI  = 3.1415926535897932;

int main(){                 ///create menu with switch or if else


    int choice ;
    double radius=1, height=1;   //variables for sphere, cap
    double value=0, result=0;

                            ///call menu and store return values in choice

  while(choice!= 4 ){

   choice = menu();

    switch(choice){
     case 1: {
                 cout << "\nEnter value > zero, for the following:" << endl ;
                 cout<<"\nEnter radius = " ;
                 cin >> radius ;
                 cout << "\nEnter height = " ;
                 cin >> height ;

              if (radius <=0 || height <= 0)
                 { cout << "\nERROR!! You entered a number less than or equal to zero!"
                      << endl ;
                        return 1 ;  }
            else {
                 radiusSurfArea2( radius, height ); }   ///call radiusSurfArea2 (radius, height )
                                  }
                                   break;

     case 2: {
                cout <<"\n\n Enter a value:  ";
                cin >> value;
                result = reciprocal(value);
                cout << "\n\nReciprocal of " << value <<"=" << result;
                cout <<"\n\n";
                                    }
                break;

     case 3: {disply_cslogin_Info();}
                break;

     case 4: {cout<<"\n===GOODBYE==="<<endl;
                break;}

     default: {cout<<"\nYou entered an invalid choice."<<endl;}


    }


  }

    cout << "\n\n";
    return 0;//End of main()
} ;
///============endOfMain=======================
 //calc radius & surface area of sphere, with given radius/height
    void radiusSurfArea2(float radius, float height){
// (1)  variable declarations
    cout << setprecision(5);
    float volumeSphere=0,volumeCap=0, surfAreaSphere=0, surfAreaCap=0;
// (2) Calculate ODU NOODULE: Volume  = 4/3*PI*(R^3)
     volumeSphere = (4.00000/3.00000) *PI * pow(radius,3.0) ;
// (3) Calculate ODU NOODULE: SurfaceArea  = 4*PI*(R^2)
     surfAreaSphere =  4 * PI * pow(radius, 2.0) ;
// (4) Cap: Volume  = 1/3*PI*(H^2)*(3R-H)
     volumeCap = (1.00000/3.00000)  * PI * pow(height, 2.0) * (3.0 * radius - height) ;
// (5) Cap:  SurfaceArea  = 2*PI*R*H
     surfAreaCap = 2 * PI * radius * height ;
// (9) Display to 5 sig digits(fixed,scientific notations)

    cout << fixed << showpoint << setprecision(5);
    cout <<"\n User input for Radius: "<<radius;
    cout <<"\n User input for Height: "<<height;
    cout <<"\n PI =  "<<PI;
    cout << scientific << showpoint << setprecision(5);
    cout <<"\n-------------------------------------";
    cout <<"\n Sphere Volume =\t" <<setw(8)<< volumeSphere;
    cout <<"\n Sphere Surface Area =\t" <<setw(8)<< surfAreaSphere;
    cout << fixed << showpoint << setprecision(5);
    cout <<"\n-------------------------------------";
    cout <<"\n Cap Surface Area =  " <<setw(8)<<surfAreaCap;
    cout <<"\n Cap Volume       =  " <<setw(8)<< volumeCap;
    cout<<"\n-------------------------------------\n";
  } ;
//============endOfradiusSurfArea2=================

///returns the reciprocal of the value provided!
  double reciprocal( double value ){
      double Recip ;
      Recip = 1/value ;
      return Recip ;
  } ;
 //============endOfReciprocal=================

    void disply_cslogin_Info(){
/// output program information
    cout << "**************************************\n";
	cout << "* Program Description: Menu options    *\n";
	cout << "* are provided for the user to         *\n"
	        "* choose different options/calculations*\n";
	cout << "****************************************\n\n";

};

 //============endOfInfo=================

  int menu(){
    int choice ;

    cout << "\nMenu" << endl ;
    cout << "(1) Calculate the surface area and volume of a sphere and spherical cap   " << endl ;
    cout << "(2) Calculate the reciprocal " << endl;
    cout << "(3) Display program information " << endl ;
    cout << "(4) Exit the program " << endl ;
    cout << "\n\n" ;
    cout << "Enter choice 1, 2, 3, or 4 : " ;
    cin >> choice ;

    return choice;

 }
 //============endOfMenu=================
