// creating words program
/* this program should read the @words directory and create a 
a new file with all the words.*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){

string line;
ifstream myInputFile("/usr/share/dict/words");
ofstream myOutputFile("dictionary.txt");
if(!myInputFile)
{
	cout << "Damaged or not found." << endl;
}
else{
	cout << "File found and okay!" << endl;
	while(getline(myInputFile,line)){
		myOutputFile << line << endl;
	}


	/*
	Read next line.
	save the word
	into new file.

	*/
}
myInputFile.close();
myOutputFile.close();
	//ofstream myFile;		
	//myFile.open(/usr/share/dict/words); // not sure..

	// if(myFile.is_open())	//check that there indeed is a file
	// {
	// 	cout << "ev thing ok" << endl;

	// }		
}