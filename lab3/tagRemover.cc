#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


class tagRemover{
public:
	tagRemover(fstream& inFile);
	void print();
    void removeSpecChar(string &thisLine);
	
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

            

           
            //ifall vi inte hittar en start p� denna rad
            //skriv bara ut den raden d�, och g� upp till
            //while och h�mta ny rad.
            if(line.find('<') == string::npos)
            {
                removeSpecChar(line);
                outFile << line << endl;
                continue;
            }
            
            //h�mta index f�r taggarna f�r f�rsta g�ngen
            //man kan anv�nda size_t ist�llet f�r int men 
            //resultatet �r detsamma �nd�?
            int leftTag = line.find("<"); 
            int rightTag = line.find(">");
           
            //r�kna antalet �ppningar p� raden.
        	size_t n = std::count(line.begin(), line.end(), '<');
         
            for(size_t i = 1; i <= n; ++i)
            {
            	//ifall det finns b�de start och avslut p� samma rad
            	//detta g�rs f�r s� m�nga �ppningar man hittade.
	            if(leftTag != -1 && rightTag != -1)   
	            {
	                auto tagDiff = rightTag - leftTag;
	                line.erase(leftTag, tagDiff + 1); 
	            }
           		leftTag = line.find("<");
            	rightTag = line.find(">");
            }

            //ifall det b�rjar en leftTag p� en rad och avslutas p� annan rad
            if(leftTag != -1 && rightTag == -1)
            {
                line.erase(leftTag, line.size());
                outFile << line << endl;

                //H�mta n�sta rad vi har fortfarande bara hittat en <
                while(getline(inFile,line))
                {
          			//hittar vi avslutningen p� denna raden?
                    int rightTag = line.find(">");
                    
                    //ifall vi inte hittar avslutningen p� denna raden
                    //ta d� bort hela raden.
                    if(rightTag == -1)
                    {
                        line.erase(0, line.size());
                    } 

                    //hittar vi avslutet p� denna raden s� tar vi bort
                    //fram till d�r vi hittade avslutningen och slutar
                    // samtidigt mata fler rader.
                    if(rightTag != -1)
                    {
                        line.erase(0, rightTag + 1);
                        break;
                    }

                }

                //beh�ver kolla s� sista raden inte har flera taggar
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
            removeSpecChar(line);
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


void tagRemover::removeSpecChar(string &line)
{
    //testar efter specialtecken p� ett mycket l�ttare
    //s�tt, konstigt nog funkar det f�r alla tecken
    //f�rutom <, ifall man ers�tter hejhej med < pajjas
    //hela str�ngen i output, men om det st�r hejhej funkar
    //det? �verskumt.
    while (line.find("&lt;") != std::string::npos)
    { 
        line.replace(line.find("&lt;"), 4, "<");
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