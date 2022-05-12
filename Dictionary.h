// header file for dictionary class

#ifndef DICTIONARY_H
#define DICTIONARY_H


#include "Word.h"

using namespace std;

class Dictionary
{

private:
	vector<Word> words;

public:
	// constructor to load dictionary 
	Dictionary(string fileName);

    void searchForWord(const vector<Word> &words);

    void searchForChar(const vector<Word> &words);

    void englishRule(const vector<Word> &words);
};

#endif /* DICTIONARY_H */
