#include <iostream>
#include <fstream>
#include "coding.h"

using namespace std;

int main(){



	ifstream myInFile("textToBeEnencoded.txt");
	ofstream myOutFile("encodedText.txt");
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
