#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <regex>
#include <iterator>
#include <string>

using namespace std;

	/* function checking if the number is a  prime*/
bool is_prime(const int & number)
{
    if (number < 2)
    {
            return false;
    }
    
    for (int i = 2; i < (number / 2 + 1); i++)
    {
        if (number%i == 0)
        {
            return false;
        }
    }
    return true;
}

string getAllPrimes(int n)
{
	cout << "Prime with " << n << " numbers created" << endl;
	string s;
	int numberSize = n;

		for(int i = 0; i < numberSize; i++)
		{
			if(i < 2)
			{
				s.insert(i,"C");
			}
			
			else
			{
				s.insert(i,"P");
			}
		
		}

//	cout << "Initial value: " << "\n" << s << endl;
	

	int currentChar;

	for(unsigned int index = 0; index < s.size(); index++)
	{
		currentChar = index;	

			if(is_prime(currentChar))
			{
				s.replace(currentChar,1, "P");

				unsigned int k = index;
				unsigned int numberRemeberer = k;


				while(k < s.size())
				{
					
					k += numberRemeberer;

						if (k >s.size())
						{
							break;
						}

						s.replace(k,1,"C");
					//cout << "k is " << k << endl;
				}

			 }
			 else
			 {
			 	s.replace(currentChar,1,"C");
			 }
		
	}

//	cout << "Afer the check:"<< "\n"<< s << endl;

return s;

}

void printPrimes(string s)
{
	cout << "The primes are: " << endl;
		for(unsigned int i = 0; i < s.size(); i++)
	{
		if(s.at(i) == 'P')
		{
			cout << i << " ";
		}

	}
	cout <<"\n";

}

void printLargestPrime(string s)
{
	int p = s.find_last_of("P");	//Finds the last=largest prime in the string
	cout << "The highest prime is: " << p << endl;

}

int main()
{
string stringWithAllPrimes = getAllPrimes(200);		//Creating 200 numbers
printPrimes(stringWithAllPrimes);					//Print the primes
printLargestPrime(stringWithAllPrimes);				//Print the largest prime

string primeLoads = getAllPrimes(100000);			//Creating 100,000 numbers
printLargestPrime(primeLoads);						//Printing the largest prime

}
