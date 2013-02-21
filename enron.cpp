#include <iostream>
#include <fstream>
#include <dirent.h>
#include <sys/types.h>
#include <string>
#include <vector>

#include "TrieNode.h"

using namespace std;

void recursively_read_directories(string dir_name, vector<string>& sub_dirs) {
	DIR* dir;
	struct dirent *dirp;
	dir = opendir(dir_name.c_str()); // TODO: close files

	while ((dirp = readdir(dir)) != NULL) {
		string dn = string(dirp->d_name);
		if (((dn != ".." && dn != "." && dn != ".DS_Store")) && (dirp->d_type == DT_DIR)) {
			string new_dir = dir_name + "/" + dn;
			vector<string> next_dir;			
			recursively_read_directories(new_dir, next_dir);
			for (int i=0; i<next_dir.size(); ++i) {
				sub_dirs.push_back(next_dir[i]);
			}
		} else if (dirp->d_type == DT_REG) {
			sub_dirs.push_back(dir_name + "/" + dn);
		}
	}
}

void search(string query, TrieNode& root) {
	vector<string> results = root.contains(query);
	for (int i=0; i<results.size(); ++i) {
		cout << results[i] << endl;
	}	
}

void deallocate_memory(TrieNode& root) {
	// Not of pressing importance but something that should be done
}

int main() {
	vector<string> files;
	recursively_read_directories("./skilling-j", files);

	TrieNode root(' '); // TODO: cpp errors out on '' -> empty character constant. TODO
	for (int i=0; i<files.size(); ++i) {
		ifstream infile(files[i].c_str());
		while (infile.good()) {
			string word;
			infile >> word;
			root.extend(word, files[i]);
		}

		infile.close();
	}

	search("Subject:", root);

	return 0;
}