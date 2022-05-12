// header file for word class

#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>

using namespace std;

class Word 
{

private:
    string name;
    string definition;
    string wordType;

public:
    Word(string name, string definition, string wordType)
        {
            Word::name = name;
            Word::definition = definition;
            Word::wordType = wordType;
        }

    string getName()
    {
            return name;
    }

    void printDefinition() const 
    {
            cout << name << " (" << wordType << ".) " << endl;
            cout << definition << endl;    
    
    }

};

#endif /* WORD_H */