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

	while(getline(myInputFile,line)){		//Keep getting the words.

		if(line.size() > 3)		//If we've got possibilie of triagram
		{
			//cout << "we've got triagram word" << endl;

			while(currentPosition < line.size() - 2)
			{
				for(int i = 0; i <= 2; i++)
				{
						myCharVector[i] = line.at(i + currentPosition);

				}
				// myCharVector[currentPosition] = line.at(currentPosition);
				// myCharVector[currentPosition + 1] = line.at(currentPosition + 1);
				// myCharVector[currentPosition + 2] = line.at(currentPosition + 2);

				currentPosition++;
			}

		}

		myOutputFile << line << " " << line.size() <<  " " << myCharVector[0] << myCharVector[1] << myCharVector[2]<< endl;

		memset(&myCharVector[0], 0, sizeof(myCharVector)); //Clear array
		currentPosition = 0;		//Reset positioner.
		
	}


/*	 Also need to check how many triagrams it contains,
	Add how many triagrams,
	 Add triagram in alphabetical order.
	 No uppercase letters.
	 Example: hand 2 and hand
	  */
myInputFile.close();		//Close the 2 used files.
myOutputFile.close();
}

	
}