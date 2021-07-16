/* Description: Changes public members to private
               and uses getter and setter to
               for the private functions
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//Global Constants
const int PAGE_WIDTH = 70;       //Width of screen for functions
const int NUM_ENGINEERS = 10;    //Number of engineers per billing file
const double PER_DIEM = 3206.81;   //Standard field engineer amount
const double EXPERT_RATE = 2350.99; //company rate for expert pay


//Forward Declarations,... aka Function Prototypes

/// engineer data structure.
class engineer
{
    public:


// public mutator and accessor functions for private member securityCode
    string getSecurityCode(){ return securityCode; }           // getter
    void setSecurityCode(string code) { securityCode = code; }   // setter

// add your public getter and setters here
    string getFName() { return fName; }
    void setfName (string First) { fName = First; }

    string getLName() { return lName; }
    void setlName (string Last) { lName = Last; }

    int getIdNum() { return idNum; }
    void setidNum (int idN) { idNum = idN; }

    int getNumDaysAssig() { return numDaysAssig; }
    void setNumDaysAssig (int numDays) { numDaysAssig = numDays; }

    double getBalance() { return balance; }
    void setBalance (double Bal) { balance = Bal; }

    double getExpertPay() { return expertPay; }
    void setExpertPay (double Expert) { expertPay = Expert; }


    private:
    string securityCode;        //secret code (shhh..)

    string fName;               
    string lName;               
    int idNum;                  
    int numDaysAssig;           //number of days on assignment
    double balance;             //total balance due to engineer
    double expertPay;           //amount of expert pay owed to engineer

    // moved the public members here to set them to private


};
//=======================================================


    void printengineerInfo( engineer c );
    void printengineerHeading();
    void printHeading( ostream& outs, string title, int width );




///- - - - - - function prototypes- - - - - - - - - - - - - - - - -
/// Print an engineer row in the table.
    void printengineerInfo( engineer c );
/// Print the heading for the engineer table
    void printengineerHeading();
/// Generate a Stylized Heading(do not change this function)
    void printHeading( ostream& outs, string title, int width );

/// Reorder the list (data structure) of security engineers by
    void selectSortEngineers( engineer array[], int arraySize );

/// Initialize the list (data struture) of engineers with default values.
    void initializeEngineers(engineer array[], int arraySize);

/// Read the values from the file into the list of engineers.
    void readInEngineers(fstream& inFile, engineer team[], int arraySize);

/// Calculate the balance due
    void calcBalance(engineer team[], int arraySize);

//---------------------------------------------------------
int main(){

	//Variable Declarations
	string dataFile = "";	        
	double averagExpertPay = 0.0;	// average expert pay multiplier per engineer
	double averageRevenue = 0.0;	// average revenue paid per engineer

    //Declare an array of engineers. 
	engineer engineer_List[NUM_ENGINEERS];


	//Initialize array of security engineers with default values
    initializeEngineers(engineer_List,NUM_ENGINEERS);

	// input file stream for engineer reimbursement data
    fstream inFile;


	//Get the name of a file from the user
//	cout << "Enter name of the Engineer Reimbursement data file: ";
//	cin >> dataFile;

    dataFile = "engineers.txt";
	//Open the file
	inFile.open(dataFile.c_str());

	//Validate the file opened.
	if (!inFile)
	{   printHeading(cerr,"Unable to open ./" + dataFile,PAGE_WIDTH);
		return 1;
	}

	//Read in the data for each of the 10 security engineers. 
    readInEngineers(inFile,engineer_List,NUM_ENGINEERS);

	//calculate balance due. 
    calcBalance(engineer_List,NUM_ENGINEERS);

	//Print the list of engineers in the order it was provided.
    printHeading(cout,"Security engineer Payment Data: " + dataFile,PAGE_WIDTH);
	printengineerHeading();
	for (int i = 0; i < NUM_ENGINEERS; i++)
	{
		printengineerInfo(engineer_List[i]);
	}
    cout << endl;


	//Calculate running sum for average expert pay, and for average revenue
	for (int i = 0; i < NUM_ENGINEERS; i++)
	{
		averagExpertPay += engineer_List[i].getExpertPay();
		averageRevenue += engineer_List[i].getBalance();
	}
	///Calculate average values for expert pay and
	averagExpertPay /= NUM_ENGINEERS;
	averageRevenue /= NUM_ENGINEERS;

    ///Print a summary of data
    printHeading(cout, "Summary of payments", PAGE_WIDTH);
    cout << fixed << setprecision(2) << right
    << setw(60) << "Avg Expert Pay per Engineer: "
    << setw(10) << averagExpertPay << endl
    << setw(60) << "Avg Revenue paid per Engineer: "
    << setw(10) << averageRevenue << endl;

///=====================================================
///Reorder the list of Engineers by last name by invoking the
/// selection sort function.
    selectSortEngineers(engineer_List,NUM_ENGINEERS);

///=====================================================
    printHeading(cout,"Engineers: Alphabetical by Last Name",PAGE_WIDTH);
	printengineerHeading();
    ///Print engineers alphabetically by last name
	for (int i = 0; i < NUM_ENGINEERS; i++)
	{
		printengineerInfo(engineer_List[i]);
	}
    cout << endl;
///====================================================
    printHeading(cout,"Stat: Engineer Expert Pay (Above Avg)",PAGE_WIDTH);
	printengineerHeading();
    ///Only print the engineers whose expert pay
    /// is GREATER THAN the average expert pay.

	for (int i = 0; i <NUM_ENGINEERS; i++)
	{
	    if ((engineer_List[i].getExpertPay())  > averagExpertPay)
            printengineerInfo(engineer_List[i]);
	}


    // - - - - - - - - - - - - - - - -
    cout<<"\n\n\n";
	inFile.close();     //Close the input file
    return 0;
}///--end of main()-------------------------------------------------
///====================================================
///----------------------------------------------------------------
/// Calculate and store the balance due for each engineer on the team.
//Find avg expert pay by multiplying number of days assigned by the
// constant for expert pay.
void calcBalance(engineer team[], int arraySize){
        string tempCode;
        for (int i = 0; i < arraySize; i++){
        int days =team[i].getNumDaysAssig();
        team[i].setExpertPay((EXPERT_RATE*days));
		team[i].setBalance((PER_DIEM*days)+team[i].getExpertPay());
		//----------------
		tempCode = team[i].getSecurityCode();
        int codeLength = tempCode.length();

        int daysLength = team[i].getNumDaysAssig();
		//----------------
		if(  (codeLength<7 ) &&  (daysLength>5)  )
         team[i].setBalance(team[i].getBalance() + (team[i].getExpertPay()));
      }
    }
///----------------------------------------------------------------
/// Read the values from the file into the list of engineers,
void readInEngineers(fstream& inFile, engineer team[], int arraySize){
        string First,Last,code;
        int idN, numDays;

        for (int i = 0; i < arraySize; i++){
		 inFile >> First >> Last >> idN >> code >> numDays;
		 team[i].setfName(First);
		 team[i].setlName(Last);
		 team[i].setidNum(idN);
		 team[i].setSecurityCode(code);
		 team[i].setNumDaysAssig(numDays);
        }
    }
///----------------------------------------------------------------
/// Print the contents of each security engineer object
void printengineerInfo(engineer c) {
	int width = 12;
	cout << left

		<< setw(width) << c.getLName()
		<< setw(width) << c.getFName()
        << setw(width - 4) << c.getIdNum()
		<< setw(width + 2) << c.getSecurityCode()
		<< setw(width) << c.getNumDaysAssig()

		<< setprecision(2) << fixed << right
		<< setw(width) << c.getBalance() << endl;
	cout.unsetf(ios::fixed);
}
///----------------------------------------------------------------
/// Print specific heading info for each engineer: Name,ID,Code,Days,Balance
void printengineerHeading() {
	int width = 12;
	cout << left
		<< setw(width) << "Last Name"
		<< setw(width) << "First Name"
        << setw(width - 4) << "ID"
		<< setw(width + 2) << "Code"
		<< setw(width + 2) << "Days"
		<< setw(width) << "Balance Due"
		<< endl;
}
///----------------------------------------------------------------
/// Prints out a custom heading: specify title, width.
void printHeading(  ostream& outs, string title, int width ) {
     //Declare Variables
     int autoWidth = 0;
     autoWidth=(width/2)-(title.length()/2)+title.length();
     outs << "\n"
    << left  << setfill('*') << setw( width ) << "*" << "\n"
    << right << setfill(' ') << setw( autoWidth ) << title << "\n"
    << left  << setfill('*') << setw( width ) << "*" << "\n";
     //reset cout
     outs.clear();
     outs.fill(' ');
}
///-----------------------------------------------------------------

/// Implement Selection Sort Algorithm: sort the team of engineers.
///Sort the list of personnel by specified criteria (last name here)
void selectSortEngineers( engineer c[], int arraySize ) {

    //  - sort array from index [0] to a[n-1]

	int i,j,minIndex;   //i & j are loop variables, minIndex stores index number of
                    //minimum value we are sorting by
	for (j = 0; j < arraySize - 1; j++)
	{   // find minimum value in unsorted part of list   a[j .. n-1]
	    // begin by storing first value
      minIndex = j;
      for ( i = j + 1; i < arraySize; i++)  // loop and
       {
         if (c[i].getLName() < c[minIndex].getLName())   //compare for smallest value
          {   minIndex = i;  }                // store new minimum value
       }
      if ( minIndex != j )  //if current minimum is not our new minimum
       {  swap( c[j], c[minIndex] );}       //Swap it with the current position
	}
}
///--------------------------------------------------------------
/// Initialize the list of engineer objects to known values.
void initializeEngineers(engineer team[], int arraySize){
        	//Initialize array of containing the team of engineers
	for (int i = 0; i < arraySize; i++)
	{
		team[i].setfName("");
		team[i].setlName("");
		team[i].setidNum(0);
		team[i].setSecurityCode("");
		team[i].setNumDaysAssig(0);
		team[i].setExpertPay(0.0);
		team[i].setBalance(0);
	}
}
///--------------------------------------------------------------
