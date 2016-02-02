#include <iostream>
#include <fstream>
#include "coding.h"

using namespace std;

int main(int argc, char** argv){

	string encodedfilename(argv[1]);
	encodedfilename = encodedfilename.substr(0,encodedfilename.length());
	encodedfilename.append(".enc");

	string inputFile(argv[1]); 
	inputFile = inputFile.substr(0,inputFile.length());
	inputFile.append(".txt");

	ifstream myInFile(inputFile);
	ofstream myOutFile(encodedfilename);
	char c;
	if(myInFile.is_open() && myOutFile.is_open()){
		while((myInFile.get(c))){

			
			unsigned char temp = static_cast<unsigned char>(c);


			myOutFile << Coding::encode(temp);

				
		}
		myOutFile.close();
		myInFile.close();
	}
	else{
		cout << "something went wrong" << endl;
	}

}
