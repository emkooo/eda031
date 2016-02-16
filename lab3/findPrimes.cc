#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <regex>
#include <iterator>
#include <string>

using namespace std;

int main()
{

	string s;
	int numberSize = 100;


	for(int i = 0; i < numberSize; i++)
	{

		s += static_cast<char>((i % 10) + '0');
		//s += (char) ((i % 10) + '0');
		
	}

	cout << s;

	// int primeCounter = 0;
	// while(primeCounter < 10)
	// {

	// }


	// 	for(int index = 0; index < 10; index++)
	// 	{
	// 		cout << s[index] << endl;

	// 	}



}
