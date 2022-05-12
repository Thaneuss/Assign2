// main program file

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // necessary for count() function
#include <fstream>      // necessary for reading text file
#include <limits>       // necessary for input validation in timesToOccur function

#include "ExtendedDictionary.h"

using namespace std;

int main()
{
	// create the dictionary
	ExtendedDictionary dic1("dictionary2022_S1.txt");
	
    int choice = 1;

    while (choice >= 1 && choice <= 4)
    {
            cout << "\nDictionary Loading Program"
            "\nPlease Enter a Corresponding Number to Procede;"
            "\n1) Search For Word"
            "\n2) Search For Character" 
            "\n3) Find Words With 'q' Not Follwed By 'u'" 
            "\n4) Find Palindromes"
            "\n5) Q" << endl;

            cin >> choice;

            // switch...case used here, more efficient than chained if...else if loops
            switch (choice)
            {
                case 1:
                        Dictionary :: searchForWord(words); 
                        break;
                case 2:
                        Dictionary :: searchForChar(words);
                        break;
                case 3:
                        Dictionary :: englishRule(words);
                        break;
                case 4:
                        ExtendedDictionary :: palindrome(words)
                        break;
                case 5:
                        cout << "Exiting Program" << endl;
                        choice = 0;
                        break;
                default:
                        cout << "Invalid Input, Please Choose 1-4" << endl;
                        break;
            }
    }       

};
