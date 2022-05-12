// .cpp file for dictionary class

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // necessary for count() function
#include <fstream>      // necessary for reading text file
#include <limits>       // necessary for input validation in timesToOccur function
#include <random>

#include "ExtendedDictionary.h"

using namespace std;

// constructor to load dictionary 
Dictionary :: Dictionary(string fileName)
{
    ifstream myFile(fileName);
    
    if (myFile.is_open())
    {
        string line;
        string name;
        string definition;
        string wordType;
        string currentWord = "none";

        // open file
        while (!myFile.eof())
        {
                getline(myFile, line);
                if (!(line.substr(0,2) == "**"))
                {
                        getline(myFile, name);
                        getline(myFile, definition);

                        Word newWord(name, definition, line);
                        words.push_back(newWord);
                }
        } 
            myFile.close();
    }
        else cout << "Unable to open file";

}

void Dictionary :: searchForWord(const vector<Word> &words)
{

    string searchterm;
    bool counter = false;
    
    cout << "\nEnter Word to Search For: ";
    
    cin >> searchterm;


    for (Word word : words)//int i = 0; i < linecount; i++)
    {
            if (word.getName() == searchterm)
            {
                    word.printDefinition();
                    counter = true;
                    break;
            }
    }

    if (counter == false)
    {
            cout << "It Seems The Word " << "'" << searchterm << "'" << " Does Not Appear Within Dictionary" << endl;
    }
};

void Dictionary :: searchForChar(const vector<Word> &words)
{
    char charSearch;
    int timesToOccur;
    
    // explained in comment block before comparison
    bool counter = false;

    // this loop performs type validation on for "charSearch". This is done with the isdigit() function. This checks if an input is a digit or a 
    // character. If the input is a digit user is prompted again for the input, if input is not a digit it is presumed to be a valid character and 
    // the program proceeds. Interestingly the type validation for "timesToOccur" is enough to cause the searchForChar() function to return its error 
    // message however having both variables validated is more robust.
    while(true)
    {
            cout << "\nEnter Character to Search For: ";

            cin >> charSearch;

            if (isdigit(charSearch))
            {
                    cout << "Please Enter a Valid Character" << endl;
            }

            else if (isdigit(charSearch) == false)
            {
                    break;
            };
    };

    // this loop performs type validation on for "timesToOccur". This is done in part with (numeric_limits<streamsize>::max(),'\n') imported from 
    // limits. Similar to the while loop above if the input is not an integer, cin will fail and set an error flag. This must be cleared and the
    // input disregarded so that input can be taken from the stream again. If cin does not fail the input is valid.
    while(true)
    {
            cout << "Minimum Number of Occurences: ";
            
            cin >> timesToOccur;

            if (cin.fail())
            {
                    cout << "Please Enter a Valid Integer\n" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else if (!cin.fail())
            {
                    break;
            };
    };

    // due to the for loop the actual search for the words containing a character a specified number of times occurs on each line due to linecount.
    // Using a normal if...else if loop here would result in words being printed until a word is found where the number of occurences
    // is less than the number required. The first instance of this would be printed and then the program would drop from the loop. To fix this 
    // a flag of sorts called "counter" is set to false at the start of the function. If even a single word is found during the search the words are 
    // printed as expected. If all words are checked and the flag is still false then we know the search was not successful.
    for (Word word : words)//int i = 0; i < linecount; i++)
    {
            // had to split like this because doing it inline was causing a seg fault ;(
            string currentWord = word.getName();
            if (count(currentWord.begin(), currentWord.end(), charSearch) >= timesToOccur)
            {
                    cout << word.getName() << endl;
                    counter = true;
            }
    }
    
    if (counter == false)
    {
            cout << "It Seems The Char " << "'" << charSearch << "'" << " Does Not Appear " << timesToOccur << " Time/s Within Dictionary" << endl;
    }
};

void Dictionary :: englishRule(const vector<Word> &words)
{       
    for (Word word : words)//int i = 0; i < linecount; i++)
    {
            if (word.getName().find('q') != std::string::npos)
            {
                    if (word.getName()[(word.getName().find('q') + 1)] != 'u')
                    {
                            cout << word.getName() << endl;
                    }
            }
    };
};
