#ifndef TRIENODE_H
#define TRIENODE_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class TrieNode {
	public:
		TrieNode(const char letter_);

		// Returns a vector of strings representing a list of emails that contain
		// the provided word
		vector<string> contains(string word);

		// Given a word and a filename, add that word to the Trie
		void extend(string word, string eamil);

		// Add a given email to a TrieNode element
		void add_email(string email);

		~TrieNode();

	private:
		char letter;
		map<char, TrieNode*> children;
		vector<string> emails; // an 'email' corresponds to the unique path to the email file

		// These should be set by the TrieManager and used in contains
		map<char, int> start_offset;
		map<char, int> end_offset;		
};

#endif