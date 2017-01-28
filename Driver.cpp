#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

#include "TrieDictionary.h"

using namespace std;

void display(const char* word, char delim);

int main(int argc, char** argv)
{
	//char input[256];	
	string input;
	bool charCase = false;
	char c;
	
	cout << "Would you like all words to be lowercase or uppercase? (l or u): ";
	cin >> c;
	
	charCase = tolower(c) == 'l' ? true : false;
	
	TrieDictionary myDictionary(charCase);
	
	// cout << "Please enter a word to be added to the dictionary: ";
	// getline(cin, input);
	
	// display(&input.at(0), '\0');
	
	//scanf("%100[^\n]", input);
	
	string test;
	
	test = "BRETT";
	myDictionary.insert(&test.at(0));	
	
	test = "NORMA";
	myDictionary.insert(&test.at(0));	
	
	test = "BRANDON";
	myDictionary.insert(&test.at(0));	
	
	test = "ANTWAN";
	myDictionary.insert(&test.at(0));	
	
	test = "SALLY";
	myDictionary.insert(&test.at(0));
	
	myDictionary.lexiDisplay();
	
	return 0;
}

void display(const char* word, char delim)
{	
	if(*word != '\0')
	{
		cout << "Your word: ";
		
		while(*word != '\0')
			cout << static_cast<char>(tolower(*word++)) << delim;	
		
		cout << "\n";
	}
	else
		cout << "No word to display\n\n";
}