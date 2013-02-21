#include "TrieNode.h"

#include <iostream> // TODO REMOVE

// Considered having a TrieManager object that each TrieNode uses to write itself.
// Discovered one rather glaring issue, however, with writing to one file. As I construct
// TrieNodes, the change size as they are modified.  

TrieNode::TrieNode(const char letter_) :
	letter(letter_) {}

void TrieNode::extend(string word, string email) {
	if (word == "") {
		return;
	}

	char l = word[0];
	TrieNode* child;
	if (children.find(l) != children.end()) {
		child = children[l];
		child->add_email(email);
		// Alternatively, read child node from disk either using offsets (old strategy) or TrieManager
	} else {
		child = new TrieNode(l);
		child->add_email(email);
		children[l] = child;
		// Alternatively,
		// offsets = TrieManager.write_TrieNode(this);
		// start_offset[l] = offsets.first;
		// start_offset[l] = offsets.second;
	}

	child->extend(word.substr(1), email); 
}

vector<string> TrieNode::contains(string word) {
	// Note: this should use the start_offset and end_offsets and the TrieManager. Not quite there yet.
	if (word == "") {
		return emails;
	}

	char l = word[0];

	if (children.find(l) != children.end()) {
		return children[l]->contains(word.substr(1));
	} else { // No matches
		return emails;
	}
}

void TrieNode::add_email(string email) {
	emails.push_back(email);
}

TrieNode::~TrieNode() {}