#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int year, month, day;
	char c;
	bool validInput = false;

	while ((cin) && !validInput)
	{
		cout << "Enter a date in the form YYYY-MM-DD: " << flush;
		cin >> year >> c >> month >> c >> day;

		// Check to see if this is a valid date
		// The Gregorian calendar began On Oct 15, 1582. Earlier dates
		// are invalid.
		if (year < 1582)
			validInput= false;
		else if (year == 1582 && month < 10)
			validInput = false;
		else if (year == 1582 && month == 10 && day < 15)
			validInput = false;
		// Months must be in the range 1..12
		else if (month < 1 || month > 12)
			validInput = false;

		// Days must be in the range 1..K where K is the number of
		// days in that month.
		else
		{
			int numberOfDaysInMonth = 0;
			switch (month)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					numberOfDaysInMonth = 31;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					numberOfDaysInMonth = 30;
					break;
				case 2:
					if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
						numberOfDaysInMonth = 29;
					else
						numberOfDaysInMonth = 28;
			}

			if (day < 1 || day > numberOfDaysInMonth)
				validInput = false;
			else
				validInput = true;
		}

		if (!validInput)
		{
			cout << "Sorry, that is not a valid date" << endl;
			string garbage;
			getline (cin, garbage); // discard the rest ofthe input line
		}
	}

	if (!cin)
	{
		cout << "Could not obtain valid input." << endl;
		return -1;
	}



	// Add up the number of days in all earlier months
	// of this year
	int sum = 0;
	for (int m = 1; m < month; ++m)
	{
		int monthLength = 0;
		switch (m)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				monthLength = 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				monthLength = 30;
				break;
			case 2:
				if (((year % 4 == 0) && (year % 100 != 0))
						|| (year % 400 == 0))
					monthLength = 29;
				else
					monthLength = 28;
		}

		sum += monthLength;
	}

	// Then add the day number to that sum
	int dayNum = sum + day;
	cout << setw(2) << setfill('0') << month
			 << "/" << setw(2) << setfill('0') << day << "/"
			 << setw(4) << year;
	cout << " is day #" << dayNum << " of that year." << endl;

	return 0;
}











