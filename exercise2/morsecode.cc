#include "morsecode.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

MorseCode::MorseCode() {
	
	ifstream morseFile("morse.def");
	vector<string> morseVector;
	vector<string> alphabetVec;



	string alphabet;
	string morse;
	string id;
	string id2;
	int counter = 0;
	
	if(morseFile.is_open()){
	
		while(morseFile.good()) {
		
			getline(morseFile, alphabet, '\t');
			getline(morseFile, morse);
			istringstream iss(alphabet);			
			iss >> id;
			alphabetVec.push_back(id);
			istringstream iss2(morse);
			iss2 >> id2;
			morseVector.push_back(id2);
			++counter;
			
		}

		/* Used for testing vectors...

		for( unsigned int j = 0; j <= alphabetVec.size(); j++){
			cout << "Alphabet vector at pos: " 	<< j << " = " << alphabetVec.at(j) << endl;
			cout << "Morse vector at pos: " 	<< j << " = " << morseVector.at(j) << endl;
		}
		*/

	} else {
		cout << "Could not open file" << endl;
	}

	

}

string MorseCode::encode(const string& text) const {
	string result;
	vector<string> resultVec;
	string temp;
	vector<char> tempVec;
	
	char myArray[27];
	text.copy(myArray,text.length()+1);

	
	
	//strcpy(myArray, text.c_str());

	//istringstream iss(text);
	//while(iss >> temp){
	//	tempVec.push_back(temp);
	//}
	



	for( unsigned int j = 0; j <= tempVec.size(); j++){
			//cout << "result vector at pos: " 	<< j << " = " << alphabetVec.at(j) << endl;
			cout << "temp vector at pos: " 	<< j << " = " << tempVec.at(j) << endl;
		}

	return "";
}

string MorseCode::decode(const string& code) const {
	return "";
}
