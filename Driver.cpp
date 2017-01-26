#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void display(char word[]);

int main(int argc, char** argv)
{
	char input[256];
	
	cout << "Please enter a word to be parsed: ";
	scanf("%100[^\n]", input);
	
	display(input);
	
	return 0;
}

void display(char* word)
{
	if(*word != '\0')
	{
		cout << "Your word: ";
		
		while(*word != '\0')		
			cout << *word++ << "\t";
		
		cout << "\n";
	}
	else
		cout << "No word to display\n\n";
}