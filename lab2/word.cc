#include "word.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Word::Word(const string& w, const vector<string>& t) {
	thisWord = w;
	wordVector = t;
}

string Word::get_word() const {
	return thisWord;
}

unsigned int Word::get_matches(const vector<string>& t) const {

unsigned int counter = 0;


// TEST EXEMPEL
unsigned int counterI = 0;
unsigned int counterJ = 0;



 while(counterI < t.size() && counterJ < wordVector.size())		// Starting of by one vector element
{
	if(t.at(counterI) == wordVector.at(counterJ))	//if we have found matches, increase all counters incl "matches"
	{
		counter++;
		counterI++;
		counterJ++;
	}	
		else if(t.at(counterI) < wordVector.at(counterJ))		//We've passed all strings in second vector
		{
			counterI++;								//get new vector from vec 1
		
		} else
		{
			counterJ++;

		}
		

}

	return counter;
}
