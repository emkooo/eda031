#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using namespace std;

Dictionary::Dictionary() {
	//unordered_set<string> mySet;		//Words are going to be stored here.
	//mySet;

	// ofstream myFile;
	// myFile.open("words.txt");

	ifstream myFile("words.txt");		//Read our .txt file

	if(!myFile)		//if file was not found
	{
		cout << "File damaged or not found" << endl;
		

	}
	else
	{
		cout << "File okay!" << endl;

		// string lol;
		// getline(myFile,lol);
		// cin >> lol;
		// cout << "the first thing we see is = " <<  lol << endl;

		string line;

		/* Problematical since we get the whole line, we only want first string */
		while(getline(myFile,line))		//Gets the line.
		{
			getline(myFile,line, ' ');	//Gets the string until 1st whitespace.

			//cin >> line;
			mySet.insert(line);			//Inser that word into the set
		}

myFile.close();		//close the file
	
	
}

}

bool Dictionary::contains(const string& word) const {

	///unordered_set<string> mySet;

	unordered_set<string>::const_iterator got = mySet.find(word);
	if(got == mySet.end()){
		return false;
	}
	return true;


	return true;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
