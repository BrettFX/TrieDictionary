#ifndef TRIEDICTIONARY_H_
#define TRIEDICTIONARY_H_

#include <iostream>
#include <string>
#include <vector>

class TrieDictionary
{
	private:
		
		static const int ALPHABET_SIZE = 26;
		static const int LOWER_CASE = 'a';
		static const int UPPER_CASE = 'A';
	
		struct TrieNode
		{
			TrieNode* parent;
			TrieNode* children[ALPHABET_SIZE];
			int occurrences;					
		};
		
		TrieNode* root;
		
		std::vector<char> charsInWord;
		
		/**
		* Keeps track of all the memory allocations for a quicker release
		* when the object is destroyed
		* */
		std::vector<TrieNode*> mallocs;
		
		/**
		* Add a word to the dictionary
		*
		* @param currentNode the currentNode in traversing the Trie tree
		* @param word the word to be added to the dictionary
		* */
		void insert(TrieNode* currentNode, const char* word);
		
		/**
		* Displays the Trie tree in lexicographical order (pre-order)
		*
		* @param currentNode the node that will be used in traversal		
		* */
		void lexiDisplay(TrieNode* currentNode);
		
		/**
		* Determine if the character in question (TrieNode) belongs to the Trie structure
		*
		* @param node the node in question
		* @param word the word in question
		*
		* @return if found: the node that was found in the search; else: null;
		* */
		TrieNode* search(TrieNode* currentNode, const char* word);
	
	public:
	
		TrieDictionary();
	
		/**
		* Add a word to the dictionary		*
		* 
		* @param word the word to be added to the dictionary
		* */
		void insert(const char* word);		
		
		/**
		* Deletes the node in question based on the return value of the search method
		*
		* @param currentNode the current node in traversing the Trie tree
		* @param word the word to be deleted from the Trie tree
		* */
		void remove(TrieNode* currentNode, const char* word);
		
		/**
		* Displays the Trie tree in lexicographical order (pre-order)
		* */
		void lexiDisplay();		
		
		~TrieDictionary();
	
};

#endif /*TRIEDICTIONARY_H_*/