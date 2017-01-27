#ifndef TRIEDICTIONARY_H_
#define TRIEDICTIONARY_H_

#include <iostream>
#include <string>
#include <vector>

class TrieDictionary
{
	private:
		struct TrieNode
		{
			char key;
			int value;	
			TrieNode* next;
			TrieNode* children;
		};
		
		TrieNode* root;
		
		int numAllocs;
		TrieNode* allocator[50];
	
	public:
	
		TrieDictionary();
	
		/**
		* Add a word to the dictionary
		*
		* @param currentNode the currentNode in traversing the Trie tree
		* @param word the word to be added to the dictionary
		* */
		void insert(TrieNode* currentNode, char* word);
		
		/**
		* Determine if the character in question (TrieNode) belongs to the Trie structure
		*
		* @param node the node in question
		* @param word the word in question
		* */
		bool search(TrieNode* node, char* word);
		
		~TrieDictionary();
	
};

#endif /*TRIEDICTIONARY_H_*/