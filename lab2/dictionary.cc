#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>


using namespace std;

Dictionary::Dictionary() 
{
	ifstream myFile("words.txt");		//Read our .txt file

	if(!myFile)		//if file was not found
	{
		cout << "File damaged or not found" << endl;
		
	}
	else
	{
		cout << "File okay!" << endl;

		string line;
		while(getline(myFile,line))		//Gets the line.
		{			
		vector<string> ourWords;
		istringstream split(line);
		for(string each; getline(split,each, ' '); ourWords.push_back(each))
			;
				string theWord = ourWords[0];

				mySet.insert(theWord);

				if(theWord.size() < MAXWORDLENGTH)
				{
				 	vector<string> theTriagram (stoi(ourWords[1]));

						for(unsigned int i = 2; i < ourWords.size(); i++)
						{
							theTriagram[i - 2] = ourWords[i];
						}						
							Word vE(theWord,theTriagram);
							words[theWord.size()].push_back(vE);
				}
			}
								myFile.close();		//close the file	
	}
}

bool Dictionary::contains(const string& word) const 
{

	unordered_set<string>::const_iterator got = mySet.find(word);
		if(got == mySet.end())
		{
			return false;
		}
			return true;

}

void Dictionary::rank_suggestions(vector<string>& t, const string& word) const
{ 

	 vector<string> rankedWords [MAXWORDLENGTH];
	 unsigned int counter = 0;
	 int d[26][26] = { {0} };		//The matrix.
	 int totalCost;

	 while(counter < t.size())
	 {
	 	string currentWord = t[counter];

	 				for(unsigned int i = 1; i< word.size(); i++)
	 				{ 
	 					char oneCharInFirstWord = word.at(i-1);

	 					for(unsigned int j = 1; j<currentWord.size(); j++)
	 					{
	 						char oneCharInSecondWord = currentWord.at(j-1);
	 						if(oneCharInFirstWord == oneCharInSecondWord)
	 						{
	 							d[i][j] = d[i-1][i-1];		//Is the start value?!
	 							//cout << d[i][j] << endl;

	 						}	 else
	 							 {
	 								int temp1 = d[i-1][j-1] + 1;
	 								int temp2 = d[i-1][j] + 1;
	 								int temp3 = d[i][j-1] +1;
	 								int dMinValue = min(temp1,min(temp2,temp3));
	 								d[i][j] = dMinValue;	 								
	 							 }
	 					}
	 					totalCost = d[word.size() -1][currentWord.size() - 1];
	 					//cout << "Totalcost is:"<<totalCost<< endl;
	 				}
		
			rankedWords[totalCost].push_back(currentWord);
			counter++;
	 }

	int current=0;
	for(unsigned int s=0; s<25; s++)
	{
		for(unsigned int r =0; r<rankedWords[s].size(); r++)
		{
			t[current] = rankedWords[s][r];
			//cout << t[current] << endl;

					current++;
		}
	}

}

void Dictionary::add_trigram_suggestions(vector<string>& t, const string& word) const
{
	int stringSize = word.size();		// get size of string
	int currentPosition = 0;
	string s = word;
	vector<string> myStringVector;
 
	if(stringSize > 3)
	{
		char myCharVector[3];
		while(currentPosition < stringSize - 2)
		{			
			string temps = "";
			for(int i = 0; i <= 2; i++)
			{
					myCharVector[i] = s.at(i + currentPosition);
					temps = temps + myCharVector[i];
			}
			myStringVector.push_back(temps);

			currentPosition++;
		}

		sort(myStringVector.begin(),myStringVector.end());			//Sorts the vector

		for(int j = stringSize -1; j <= stringSize + 1; j++)
			{	
					//cout << " stringSize is " << stringSize << endl;
					for(unsigned int k = 0; k< words[j].size() - 1; k++)
					{
					
						if(words[j][k].get_matches(myStringVector) >= myStringVector.size()/2)
						{ 		
							t.push_back(words[j][k].get_word());
						}
					}
			}
	}

else{
		vector<Word> tempOne = words[stringSize];
			for(unsigned int a = 0 ; a < tempOne.size(); a++)
			{
				t.push_back(tempOne[a].get_word());

			}
	}
			sort(t.begin(),t.end());
}

void Dictionary::trim_suggestions(vector<string>& t) const
{
	t.resize(5);

}

vector<string> Dictionary::get_suggestions(const string& word) const 
{
		vector<string> suggestions;
		add_trigram_suggestions(suggestions,word);
		rank_suggestions(suggestions,word);
		trim_suggestions(suggestions);



	return suggestions;
}