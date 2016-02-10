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

string valueInI;
string valueInJ;

while(counterI <= t.size())		// Starting of by one vector element
{
	if(valueInI[counterI] == valueInJ[counterJ])	//if we have found matches, increase all counters incl "matches"
	{
		counter++;
		counterI++;
		counterJ++;
	}	
		else if(counterJ == wordVector.size())		//We've passed all strings in second vector
		{
			counterI++;								//get new vector from vec 1
		
		} 
		counterJ++;

}


/*	for(unsigned int i =0; i < t.size(); i++)		//Iterate trough vector 't'
	{
		string value = t[i];	// get value

		//see if it is contained in our vector

		for(unsigned int j=0; j < wordVector.size(); j++)		//iterate trough our vector
		{
			string ourVector = wordVector[j];			//get triagram

			// if(ourVector.at(0) != value.at(0)){			//if the first char is different
			// 	break;									//possible increase of efficiency?
			// }	
			if(value == wordVector[j])				//else if the words match
			{
				counter++;
				//i=j;	//have i to j since its alpabetical								//increase the counter
				break;		//In case we found what we are looking for,
							//no need to continue searching for same element.

			}
		}

	}
*/

	return counter;
}
