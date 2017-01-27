#include "TrieDictionary.h"

TrieDictionary::TrieDictionary()
{
	numAllocs = 0;
	root = NULL;	
}

/**
* Add a word to the dictionary
* 
* @param word the word to be added to the dictionary
* */
void TrieDictionary::insert(char* word)
{
	if(!root)
		root = new Node();
	
	insert(root, word);
}
	
/**
* Add a word to the dictionary
*
* @param currentNode the currentNode in traversing the Trie tree
* @param word the word to be added to the dictionary
* */
void TrieDictionary::insert(TrieDictionary::TrieNode* currentNode, char* word)
{
	while(*word != '\0')
	{
		//Determine if the currentNode's children is pointing to null
		if(!currentNode->children[*word - CASE])
		{
			//Create a new node at the child that was pointing to null and set that child's parent equal to the currentNode
			currentNode->children[*word - CASE] = new Node();
			currentNode->children[*word - CASE]->parent = currentNode;
		}
		
		currentNode = currentNode->children[*word - CASE];
		word++;
	}
	
	//Once the null character has been reached and the word is completed, increment the occurrences of the word
	currentNode->occurrences++;
}

/**
* Determine if the character in question (TrieNode) belongs to the Trie structure
*
* @param node the node in question
* @param word the word in question
*
* @return if found: the node that was found in the search; else: null;
* */
TrieDictionary::TrieNode* TrieDictionary::search(TrieDictionary::TrieNode* currentNode, char* word)
{
	//Traverse the word
	while(*word != '\0')
	{
		if(currentNode->children[*word - CASE])
		{
			//Move into the node that isn't null
			currentNode = currentNode->children[*word - CASE];
			word++;
		}
		else return NULL;
	}
	
	return currentNode->occurrences != 0 ? currentNode : NULL;
}

/**
* Deletes the node in question based on the return value of the search method
*
* @param currentNode the current node in traversing the Trie tree
* @param word the word to be deleted from the Trie tree
* */
void TrieDictionary::remove(TrieDictionary::TrieNode* currentNode, char* word)
{
	TrieNode* parent = NULL;
	bool isLeaf = true;
	
	currentNode = search(currentNode, word);
	
	//Make sure the word exists
	if(currentNode)
	{
		currentNode->occurrences--;
		
		//See if isLeaf and the node has children
		for(int i = 0; i < ALPHABET_SIZE; i++)
		{
			if(currentNode->children[i])
			{
				//Has a child; not a leaf (don't continue to the while loop since not a leaf)
				isLeaf = false;
				break;
			}
		}
		
		//Root is the only node that will have a parent that equals null (stop when the root is reached)
		while(currentNode->parent && isLeaf && currentNode->occurrences == 0)
		{
			parent = currentNode->parent;
			
			for(int i = 0; i < ALPHABET_SIZE; i++)
			{
				//Traverse the children of the parent and remove the child that is equal to the currentNode, is a leaf, and has zero occurrences
				if(parent->children[i] == currentNode)
				{
					parent->children[i] = NULL;
					delete currentNode;
					currentNode = parent;
				}
				else if(parent->children[i]) //Make sure the parent is a leaf
				{
					isLeaf = false;
					break;
				}
			}
		}
	}
}

/**
* Displays the Trie tree in lexicographical order (pre-order)
* */
void TrieDictionary::lexiDisplay()
{
	if(root)
		lexiDisplay(root)
	else
		std::cout << "No words exist in this dictionary\n";
}

/**
* Displays the Trie tree in lexicographical order (pre-order)
*
* @param currentNode the node that will be used in traversal
* @param word to be displayed
* */
void TrieDictionary::lexiDisplay(TrieDictionary::TrieNode* currentNode)
{
	//Determine if we have reached the final node
	if(currentNode->occurrences > 0)
	{		
		for(std::vector<char>::iterator it = charsInWord.begin(); it != charsInWord.end(); it++)
		{
			std::cout << *it;
		}
		
		cout << " " << currentNode->occurrences << "\n";
	}
	
	//Traverse children and find any child that exists
	for(int i = 0; i < ALPHABET_SIZE; i++)
	{
		if(currentNode->children[i])
		{
			//Push back each character into the word
			charsInWord.push_back(CASE + i);
			lexiDisplay(currentNode->children[i]);
			charsInWord.pop_back();
		}
	}
}

TrieDictionary::~TrieDictionary()
{
	
}