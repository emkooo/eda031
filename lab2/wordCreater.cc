// creating words program
/* this program should read the @words directory and create a 
a new file with all the words.*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){

string line;		//String with current line


ifstream myInputFile("/usr/share/dict/words");	// get the words
ofstream myOutputFile("words.txt");		// Insert words here

if(!myInputFile) //If we cant find the file 
{
	cout << "Damaged or not found." << endl;
}
else{
	cout << "File found and okay!" << endl;

		/*
	Read next line.
	save the word
	into new file.

	*/
unsigned currentPosition = 0;
char myCharVector[3];
vector<string> myStringVector;

	while(getline(myInputFile,line)){		//Keep getting the words.

		if(line.size() > 3)		//If we've got possibilie of triagram
		{
			string s;
			//cout << "we've got triagram word" << endl;

			while(currentPosition < line.size() - 2)
			{
				s = "";
				for(int i = 0; i <= 2; i++)
				{
						myCharVector[i] = line.at(i + currentPosition);
						s = s + myCharVector[i];

				}
				myStringVector.push_back(s);
				

				// myCharVector[currentPosition] = line.at(currentPosition);
				// myCharVector[currentPosition + 1] = line.at(currentPosition + 1);
				// myCharVector[currentPosition + 2] = line.at(currentPosition + 2);

				currentPosition++;
			}
			sort(myStringVector.begin(),myStringVector.end());			//Sorts the vector

		}

		myOutputFile << line << " " << myStringVector.size();
		for(int i =0; i<myStringVector.size(); i++)
		{
			string apa = myStringVector[i];
			myOutputFile << " " << apa;				//Remove from the last item?!

		}
		myOutputFile << endl;

		memset(&myCharVector[0], 0, sizeof(myCharVector)); //Clear array
		currentPosition = 0;		//Reset positioner.
		myStringVector.clear();
		
	}


myInputFile.close();		//Close the 2 used files.
myOutputFile.close();
}

	
}