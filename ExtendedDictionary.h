// header file for the "ExtendedDictionary" derived from the "Dictionary" base class

#ifndef EXTENDEDDICTIONARY_H
#define EXTENDEDDICTIONARY_H

#include "Dictionary.h"

using namespace std;

class ExtendedDictionary : public Dictionary
{
    public:
        ExtendedDictionary(string fileName) : Dictionary(fileName)
        {
            
        }

        // void anagram(const vector<Word> &words)
        // {
        //     string searchterm;

        //     cout << "\nEnter Word to Search For: "; 

        //     cin >> searchterm;

        //     for (Word word : words)
        //     {
        //         string currentWord = word.getName();

        //         string currentWordSorted = currentWord;

        //         if (currentWord.length() == searchterm.length())
        //         {
        //             sort(currentWordSorted.begin(), currentWordSorted.end());
        //             sort(searchterm.begin(), searchterm.end());
                    
        //             if (currentWordSorted == searchterm)
        //             {
        //                     cout << currentWord << endl;
        //             }
        //         }
        //     }

        void palindrome(const vector<Word> &words)
        {
            for (Word word : words)//int i = 0; i < linecount; i++)
            {
                string currentWord = word.getName();

                string revCurrentWord = currentWord;

                reverse(revCurrentWord.begin(), revCurrentWord.end());

                if (currentWord == revCurrentWord)
                {
                        cout << currentWord << endl;
                }
            }
        }
};

#endif /* EXTENDEDDICTIONARY_H */