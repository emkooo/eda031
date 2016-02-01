#include <iostream>
#include <fstream>
#include <cstring>
#include "coding.h"
#include <string>

using namespace std;

int main(int argc, char** argv){

	//char theFileName[] = {'.','e','n','c', '\0'};
	
	//string extension = ".enc"
	string filename(argv[1]);
	filename.append(".enc");

	ifstream myInFile(argv[1]);
	//char temp[strlen(argv)] = append(argv,theFileName);
	ofstream myOutFile(filename);
	char c;
	if(myInFile.is_open() && myOutFile.is_open()){
		while((myInFile.get(c))){

			
			unsigned char temp = static_cast<unsigned char>(c);


			myOutFile << Coding::decode(temp);

				
		}
		myOutFile.close();
		myInFile.close();
	}
	else{
		cout << "something went wrong" << endl;
	}

}
