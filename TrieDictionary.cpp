#include "TrieDictionary.h"

TrieDictionary::TrieDictionary()
{	
	TrieDictionary(true);
}

/**
* Overload constructor to allow the user to specify the case that the dictionary handles
*
* @param isLower determines if the case of each character will be treated as lowercase or uppercase
* */
TrieDictionary::TrieDictionary(bool isLower)
{
	root = NULL;
	setCase(isLower);
	
	std::cout << "currentCase = " << currentCase << "\n";
}

/**
* Sets the current case to the specified case based on the boolean outcome of the parameter
*
* @param isLower determines if the case of each character will be treated as lowercase or uppercase
* */
void TrieDictionary::setCase(bool isLower)
{
	currentCase = isLower ? LOWER_CASE : UPPER_CASE;
}

/**
* Add a word to the dictionary
* 
* @param word the word to be added to the dictionary
* */
void TrieDictionary::insert(const char* word)
{
	if(!root)
	{
		std::cout << "Creating root...\n";
		
		root = new TrieNode();
		
		root->parent = NULL;		
		root->occurrences = 0;
		
		//Push a reference to the newly created node into the mallocs vector
		mallocs.push_back(root);
	}		
	
	insert(root, word);
}
	
/**
* Add a word to the dictionary
*
* @param currentNode the currentNode in traversing the Trie tree
* @param word the word to be added to the dictionary
* */
void TrieDictionary::insert(TrieDictionary::TrieNode* currentNode, const char* word)
{
	while(*word != '\0')
	{
		//Determine if the currentNode's children is pointing to null
		if(!currentNode->children[*word - currentCase])
		{
			//Create a new node at the child that was pointing to null and set that child's parent equal to the currentNode
			currentNode->children[*word - currentCase] = new TrieNode();
			
			currentNode->children[*word - currentCase]->parent = NULL;			
			currentNode->children[*word - currentCase]->occurrences = 0;			
			currentNode->children[*word - currentCase]->parent = currentNode;
			
			//Push a reference to the newly created node into the mallocs vector
			mallocs.push_back(currentNode->children[*word - currentCase]);
		}
		
		currentNode = currentNode->children[*word - currentCase];
		word++;
	}
	
	//Once the null character has been reached and the word is completed, increment the occurrences of the word
	++currentNode->occurrences;
}

/**
* Determine if the character in question (TrieNode) belongs to the Trie structure
*
* @param node the node in question
* @param word the word in question
*
* @return if found: the node that was found in the search; else: null;
* */
TrieDictionary::TrieNode* TrieDictionary::search(TrieDictionary::TrieNode* currentNode, const char* word)
{
	//Traverse the word
	while(*word != '\0')
	{
		if(currentNode->children[*word - currentCase])
		{
			//Move into the node that isn't null
			currentNode = currentNode->children[*word - currentCase];
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
void TrieDictionary::remove(TrieDictionary::TrieNode* currentNode, const char* word)
{
	TrieNode* parent = NULL;
	bool isLeaf = true;
	
	currentNode = search(currentNode, word);
	
	//Make sure the word exists
	if(currentNode)
	{
		--currentNode->occurrences;
		
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
	{
		std::cout << "Starting at root...\n";
		
		lexiDisplay(root);
	}
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
		
		std::cout << " " << currentNode->occurrences << "\n";
	}
	
	//Traverse children and find any child that exists
	for(int i = 0; i < ALPHABET_SIZE; i++)
	{
		if(currentNode->children[i])
		{
			//Push back each character into the word
			charsInWord.push_back(currentCase + i);
			lexiDisplay(currentNode->children[i]);
			charsInWord.pop_back();
		}
	}
}

TrieDictionary::~TrieDictionary()
{
	for(std::vector<TrieNode*>::iterator it = mallocs.begin(); it != mallocs.end(); it++)
	{
		std::cout << "Deleting " << *it << "\n";
		delete *it;
	}
}