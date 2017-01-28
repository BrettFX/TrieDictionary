#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

#include "TrieDictionary.h"

using namespace std;

void display(char* word, char delim);

int main(int argc, char** argv)
{
	//char input[256];	
	string input;
	
	TrieDictionary myDictionary;
	
	// cout << "Please enter a word to be added to the dictionary: ";
	// cin >> input;
	//scanf("%100[^\n]", input);
	
	myDictionary.insert("brett");
	myDictionary.insert("norma");
	myDictionary.insert("brandon");
	myDictionary.insert("antwan");
	myDictionary.insert("sally");
	
	myDictionary.lexiDisplay();
	
	return 0;
}

void display(char* word, char delim)
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