#include "TrieDictionary.h"

TrieDictionary::TrieDictionary()
{
	numAllocs = 0;
	root = NULL;	
}
	
/**
* Add a word to the dictionary
*
* @param currentNode the currentNode in traversing the Trie tree
* @param word the word to be added to the dictionary
* */
void TrieDictionary::insert(TrieNode* currentNode, char* word)
{
	TrieNode* nodeToInsert = new TrieNode();
	nodeToInsert->key = 'a';
	nodeToInsert->value = 0;
	nodeToInsert->next = nodeToInsert->children = NULL;
	
	allocator[numAllocs++] = nodeToInsert;
}

/**
* Determine if the character in question (TrieNode) belongs to the Trie structure
*
* @param node the node in question
* @param word the word in question
* */
bool TrieDictionary::search(TrieNode* node, char* word)
{
	return true;
}

TrieDictionary::~TrieDictionary()
{
	for(int i = 0; i < numAllocs; i++)
	{
		std::cout << "Deleting: " << allocator[i] << "\n";
		delete allocator[i];
	}
}