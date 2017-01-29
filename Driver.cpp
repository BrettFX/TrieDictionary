#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

#include "TrieDictionary.h"

using namespace std;

enum Choice
{
	INSERT = 1,
	REMOVE,
	DISPLAY,
	EXIT
};

void display(const char* word, char delim);

void menu();

void renderChoice(int choice, TrieDictionary& dictionary);

int main(int argc, char** argv)
{
	int choice;
	bool charCase = false;
	char c;
	
	cout << "Would you like all words to be lowercase or uppercase? (l or u): ";
	cin >> c;
	
	charCase = tolower(c) == 'l' ? true : false;
	
	TrieDictionary myDictionary(charCase);
	
	do
	{
		do
		{
			menu();
			cin >> choice;
			
			if(choice < INSERT || choice > EXIT)
				cout << "Invalid choice.\n";
			else
				renderChoice(choice, myDictionary);
			
		}while(choice < INSERT || choice > EXIT);
	}while(choice != EXIT);
	
	return 0;
}

void menu()
{
	cout << INSERT << ". Insert\n";
	cout << REMOVE << ". Remove\n";
	cout << DISPLAY << ". Display\n";
	cout << EXIT << ". Exit\n\n";
	
	cout << ">> ";
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

void renderChoice(int choice, TrieDictionary& dictionary)
{
	string input;
	
	switch(choice)
	{
		case INSERT:
			cout << "What word would you like to insert? ";
			cin >> input;
			dictionary.insert(&input.at(0));
			break;
			
		case REMOVE:
			cout << "What word would you like to remove? ";
			cin >> input;
			dictionary.remove(&input.at(0));
			break;
			
		case DISPLAY:
			dictionary.lexiDisplay();
			break;
			
		case EXIT:
			cout << "Exiting...\n\n";
			break;
			
		default:
			cout << "Invalid choice.\n\n";
			break;
	}
}