#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

/*
Hjälpfunktion som räknar antalet funna 
strängar "toFind" i strängen "base"
returnerar antalet i int 
*/

int numberOfOccur(string toFind, string base)
{
    int occurrences = 0;
	string::size_type start = 0;

	while ((start = base.find(toFind, start)) != string::npos) 
	{
		++occurrences;
		start += toFind.length();
	}

	return occurrences;
}


int main()
{
    string line;
    ifstream inFile("test.html");
    ofstream outFile("output.txt");

	
    if(inFile.is_open() && outFile.is_open())
    {
        while(getline(inFile,line))
        {

        	/*
           	cout << "number of occur" << numberOfOccur("&lt", line) << endl;
        	if(numberOfOccur("&lt", line) != 0)
            {
            	for(int i = 0; i < numberOfOccur("&lt", line); ++i)
            	{
            		int start = line.find("&lt");
            		cout << "START IN LT: " << start << endl;
            		cout << "FIND PLACEMENT: " << line.find("&lt") << endl;
            		line.replace(start, 4, "<");
            		
            	}
            }

            cout << "number of occur" << numberOfOccur("&gt", line) << endl;
            if(numberOfOccur("&gt", line) != 0)
            {
            	for(int i = 0; i < numberOfOccur("&gt", line); ++i)
            	{
            		int start = line.find("&gt");
            		cout << "START IN GT: " << start << endl;
            		line.replace(start, 4, ">");
            		
            	}
            }

            cout << "number of occur" << numberOfOccur("&nbsp", line) << endl;
            if(numberOfOccur("&nbsp", line) != 0)
            {
            	for(int i = 0; i < numberOfOccur("&nbsp", line); ++i)
            	{
            		int start = line.find("&nbsp");
            		cout << "START IN npbs: " << start << endl;
            		line.replace(start, 6, " ");
            	
            	}
            }

            cout << "number of occur" << numberOfOccur("&amp", line) << endl;
            if(numberOfOccur("&amp", line) != 0)
            {
            	for(int i = 0; i < numberOfOccur("&amp", line); ++i)
            	{
            		int start = line.find("&amp");
            		cout << "START IN amp: " << start << endl;
            		line.replace(start, 5, "&");
            		
            	}
            }

         
			*/			


            //ifall vi inte hittar en start på denna rad
            //skriv bara ut den raden då, och gå upp till
            //while och hämta ny rad.
            if(line.find('<') == string::npos)
            {
                outFile << line << endl;
                continue;
            }
            
            //hämta index för taggarna för första gången
            //man kan använda size_t istället för int men 
            //resultatet är detsamma ändå?
            int leftTag = line.find("<"); 
            int rightTag = line.find(">");
           
            //räkna antalet öppningar på raden.
        	size_t n = std::count(line.begin(), line.end(), '<');
         
            for(size_t i = 1; i <= n; ++i)
            {
            	//ifall det finns både start och avslut på samma rad
            	//detta görs för så många öppningar man hittade.
	            if(leftTag != -1 && rightTag != -1)   
	            {
	                auto tagDiff = rightTag - leftTag;
	                line.erase(leftTag, tagDiff + 1); 
	            }
           		leftTag = line.find("<");
            	rightTag = line.find(">");
            }

            //ifall det börjar en leftTag på en rad och avslutas på annan rad
            if(leftTag != -1 && rightTag == -1)
            {
                line.erase(leftTag, line.size());
                outFile << line << endl;

                //Hämta nästa rad vi har fortfarande bara hittat en <
                while(getline(inFile,line))
                {
          			//hittar vi avslutningen på denna raden?
                    int rightTag = line.find(">");
                    
                    //ifall vi inte hittar avslutningen på denna raden
                    //ta då bort hela raden.
                    if(rightTag == -1)
                    {
                        line.erase(0, line.size());
                    } 

                    //hittar vi avslutet på denna raden så tar vi bort
                    //fram till där vi hittade avslutningen och slutar
                    // samtidigt mata fler rader.
                    if(rightTag != -1)
                    {
                        line.erase(0, rightTag + 1);
                        break;
                    }

                }

                //behöver kolla så sista raden inte har flera taggar
                //efter sig, precis som innan.
                size_t k = std::count(line.begin(), line.end(), '<');
            	for(size_t i = 1; i <= k; ++i)
            	{
            		leftTag = line.find("<");
            		rightTag = line.find(">");
            		auto tagDiff = rightTag - leftTag;
	                line.erase(leftTag, tagDiff + 1);

            	}

            }

            //skriv raden till output.
            outFile << line << endl;

        }


    inFile.close();
    outFile.close();
    }
    else
    {
       cout << "Could not open file" << endl;
    }

    return 0;
}
