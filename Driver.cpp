#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "TrieDictionary.h"

using namespace std;

void display(char* word, char delim);

int main(int argc, char** argv)
{
	char input[256];
	
	cout << "Please enter a word to be added to the dictionary: ";
	scanf("%100[^\n]", input);
	
	display(input, ' ');
	
	return 0;
}

void display(char* word, char delim)
{
	char c;
	
	if(*word != '\0')
	{
		cout << "Your word: ";
		
		while(*word != '\0')
		{
			c = tolower(*word);
			cout << c << delim;			
			word++;
		}
		
		cout << "\n";
	}
	else
		cout << "No word to display\n\n";
}