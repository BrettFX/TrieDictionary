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
	
	TrieDictionary myDictionary(false);
	
	// cout << "Please enter a word to be added to the dictionary: ";
	// getline(cin, input);
	
	// display(&input.at(0), '\0');
	
	//scanf("%100[^\n]", input);
	
	string test;
	
	//test = "brett";
	test = "BRETT";
	myDictionary.insert(&test.at(0));
	
	//test = "norma";
	test = "NORMA";
	myDictionary.insert(&test.at(0));
	
	//test = "brandon";
	test = "BRANDON";
	myDictionary.insert(&test.at(0));
	
	//test = "antwan";
	test = "ANTWAN";
	myDictionary.insert(&test.at(0));
	
	//test = "sally";
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