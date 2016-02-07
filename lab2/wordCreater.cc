// creating words program
/* this program should read the @words directory and create a 
a new file with all the words.*/


#include <iostream>
#include <fstream>
using namespace std;


int main(){
	ofstream myFile;		
	myFile.open(/usr/share/dict/words); // not sure..

	if(myFile.is_open())	//check that there indeed is a file
	{
		cout << "ev thing ok" << endl;

	}		
}