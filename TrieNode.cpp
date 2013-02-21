#include "TrieNode.h"

// Considered having a TrieManager object that each TrieNode uses to write itself.
// Discovered one rather glaring issue, however, with writing to one file. As I construct
// TrieNodes, the change size as they are modified. This poses an issue of writing 

TrieNode::TrieNode(const char letter_) :
	letter(letter_) {}

void TrieNode::extend(string word, string email) {
	if (word == "") {
		return;
	}

	char l = word[0];
	TrieNode child(' ');
	if (start_offsets.find(l) != start_offsets.end()) {
		assert(end_offsets.find(l) != end_offsets.end()); // Ensure consistency

		// read child node from disk; child = 
	} else {
		child = TrieNode(l);
		child.add_email(email);
		// offsets = TrieManager.write_TrieNode(this);
		// start_offset[l] = offsets.first;
		// start_offset[l] = offsets.second;


		// persist to disk
	}

	child.extend(word.substr(1), email); 
}

vector<string> TrieNode::contains(string word) {
	if (word == "") {
		return emails;
	}

	char l = word[0];
	if (start_offsets.find(l) != start_offsets.end()) {
		assert(end_offsets.find(l) != end_offsets.end()); // Ensure consistency TODO redundant
		// TrieNode = TrieManager.read
	} else { // No matches
		return emails;
	}
}

void TrieNode::add_email(string email) {
	emails.push_back(email);
}

TrieNode::~TrieNode() {}