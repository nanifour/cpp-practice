#include <string>
#include <iostream>
using namespace std;

/*
* Responsible for calculating the similarity between two strings using the Levenshtein distance metric
*
* // info: https://en.wikipedia.org/wiki/Levenshtein_distance
* // credit to: http://rosettacode.org/wiki/Levenshtein_distance
* @param s1: first candidate string for similarity test
* @param s2: second candidate string for similarity test
* @param return: numeric measure of distance
*/
size_t uiLevenshteinDistance(const string &s1, const string &s2)
{
	const size_t m(s1.size());
	const size_t n(s2.size());

	if( m==0 )
	{
		return n;
	}

	if( n==0 )
	{
		return m;
	}

	size_t *costs = new size_t[n + 1];

	for( size_t k=0; k<=n; k++ )
	{
		costs[k] = k;
	}

	size_t i = 0;
	for ( std::string::const_iterator it1 = s1.begin(); it1 != s1.end(); ++it1, ++i )
	{
		costs[0] = i+1;
		size_t corner = i;

		size_t j = 0;
		for ( std::string::const_iterator it2 = s2.begin(); it2 != s2.end(); ++it2, ++j )
		{
			size_t upper = costs[j+1];
			if( *it1 == *it2 )
			{
				costs[j+1] = corner;
			}
			else
			{
				size_t t(upper<corner?upper:corner);
				costs[j+1] = (costs[j]<t?costs[j]:t)+1;
			}
			corner = upper;
		}
	}

	size_t result = costs[n];
	delete [] costs;

	return result;
}

/*
* Responsible for converting a numeric score into a letter grade
*
* @param score: numeric score for conversion
* @param return: a letter grade {A, B, C, D, F} corresponding to score.
*/
char getLetterGrade(float score)
{
	if( score >= 90 )
	{
		return 'A';
	}
	else if( score >= 80 )
	{
		return 'B';
	}
	else if( score >= 70 )
	{
		return 'C';
	}
	else if( score >= 60 )
	{
		return 'D';
	}

	return 'F';
}

/*
* Responsible for printing 2d chart of letter grades
*/
void printChart(string chart[])
{
	for(int i = 0; i<5; i++)
	{
		cout << chart[i][0] << "s: " << chart[i].substr(1, chart[i].length()-1) << endl;
	}
}

/*
* Responsible for adding a single letter grade to the chart
*
* @param chart: chart array to be populated
* @param grade: letter grade to be added to chart
*/
void addGradeToChart(string chart[], char grade)
{
	switch( grade )
	{
		case 'A':
			chart[0] = chart[0] + grade;
			break;
		case 'B':
			chart[1] = chart[1] + grade;
			break;
		case 'C':
			chart[2] = chart[2] + grade;
			break;
		case 'D':
			chart[3] = chart[3] + grade;
			break;
		default:
			chart[4] = chart[4] + grade;
	}
}

/*
	Responsible for handling similarity game: similarity between a pair of words
*/
void similarityGame()
{
	// initial values are just labels for the chart grade group
	string chart[5] = {"A", "B", "C", "D", "F"};

	string firstWord = "";
	string secondWord = "";
	char letterGrade = ' ';
	int maxWordLength;
	int levenshteinScore;

	while( true )
	{
		cout << endl;
		cout << "Enter first word: ";
		getline(cin, firstWord);

		maxWordLength = firstWord.length();

		cout << "Enter second word: ";
		getline(cin, secondWord);

		if( secondWord.length() > maxWordLength )
		{
			maxWordLength = secondWord.length();
		}

		levenshteinScore = uiLevenshteinDistance(firstWord, secondWord);
		cout << endl;
		cout << "<" << firstWord << ">" << endl;
		cout << "<" << secondWord << ">" << endl;


		letterGrade = 'F';
		if( maxWordLength == 0 )
		{
			cout << "Similarity: 0%" << endl;
			cout << "Score: F" << endl;
		}
		else
		{
			levenshteinScore = (1 - (levenshteinScore/float(maxWordLength))) * 100;
			letterGrade = getLetterGrade(levenshteinScore);

			cout << "Similarity: " << levenshteinScore << "%" << endl;
			cout << "Score: " << letterGrade << endl;
		}
		addGradeToChart(chart, letterGrade);

		cout << "Continue (Y/N): ";
		cin >> firstWord;
		cin.ignore();

		if( firstWord == "N" )
		{
			cout << endl;
			printChart(chart);
			return;
		}
	}
}

/*
	Entry point
*/
int main()
{
	similarityGame();

	return 0;
}
