#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


class tagRemover{
public:
	tagRemover(fstream& inFile);
	void print();
	
private:
};

tagRemover::tagRemover(fstream& inFile)
{
    string line;
    //ifstream inFile("test.html");
    ofstream outFile("output.txt");

	
    if(inFile.is_open() && outFile.is_open())
    {
        while(getline(inFile,line))
        {

            //testar efter specialtecken på ett mycket lättare
            //sätt, konstigt nog funkar det för alla tecken
            //förutom <, ifall man ersätter hejhej med < pajjas
            //hela strängen i output, men om det står hejhej funkar
            //det? överskumt.
            while (line.find("&lt;") != std::string::npos)
            { 
                line.replace(line.find("&lt;"), 4, "lessthan");
            }
                
            while (line.find("&gt;") != std::string::npos)
            { 
                line.replace(line.find("&gt;"), 4, ">");
            }

            while (line.find("&nbsp;") != std::string::npos)
            {
                line.replace(line.find("&nbsp;"), 6, " ");
            }

            while (line.find("&amp;") != std::string::npos)
            { 
                line.replace(line.find("&amp;"), 5, "&");
            }

           
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

   
}

void tagRemover::print()
{
	string toBePrinted;
	fstream inFile("output.txt");
	if(inFile.is_open())
	{
		while(getline(inFile,toBePrinted))
		{
			cout << toBePrinted << endl;
		}
	}
}


int main()
{

	fstream myInFile("test.html");
	if(myInFile.is_open())
	{
		tagRemover tr(myInFile);
		tr.print();
	}

return 0;
}