#ifndef DICTIONARY_H
#define DICTIONARY_H
#define MAXWORDLENGTH 25

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

using namespace std;

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
//	void rank_suggestions(vector<string>& t);
	void add_trigram_suggestions(vector<string>& t, const string& word) const;

private:
	unordered_set<string> mySet;
     vector<Word> words[MAXWORDLENGTH]; // words[i] = the words with i letters,
                                		// ignore words longer than 25 letters

};

#endif
