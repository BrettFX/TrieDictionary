#ifndef TRIEDICTIONARY_H_
#define TRIEDICTIONARY_H_

#include <iostream>
#include <string>

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
	
	public:
	
		/**
		* Add a word to the dictionary
		*
		* @param word the word to be added to the dictionary
		* */
		void add(char word[]);
		
		/**
		* Determine if the character in question (TrieNode) belongs to the Trie structure
		*
		* @param node the node in question
		* @param word the word in question
		* */
		bool isMember(TrieNode* node, char word[]);
	
}

#endif /*TRIEDICTIONARY_H_*/