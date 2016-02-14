#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line;
    ifstream inFile("test.html");
    ofstream outFile("output.txt");



    if(inFile.is_open() && outFile.is_open())
    {
        int lineCounter = 0;
        while(getline(inFile,line))
        {

           // int leftTag = line.find("<"); // leftTag = positionen för lefttag.
          //  cout << "The index of leftTag is: " << leftTag << endl;

         //   int rightTag = line.find(">");
          //  cout << "The index of rightTag is: " << rightTag << endl;

           




    
           
            if(line.find('<') == string::npos)
            {
                outFile << line;
                continue;
            }
            

            int leftTag = line.find("<"); // leftTag = positionen för lefttag.
            cout << "The index of leftTag is: " << leftTag << endl;

            int rightTag = line.find(">");
            cout << "The index of rightTag is: " << rightTag << endl;


           
         
           
           
            //ifall det finns en tag som börjar och slutar på samma linje
            //måste tänka på flera tags på samma linje 
         
            if(leftTag != -1 && rightTag != -1)   
            {
                auto tagDiff = rightTag - leftTag;
                line.erase(leftTag, tagDiff + 1);
                outFile << line;
                
            }
           

            //ifall det börjar en leftTag på en rad och avslutas på annan rad
            if(leftTag != -1 && rightTag == -1)
            {
                cout << "lefttag here is? " << leftTag << endl;
                line.erase(leftTag, line.size());
                outFile << line;

                cout << "hej0" << line << endl;
               

                while(getline(inFile,line))
                {
                    cout << "hej" << line << endl;
                    int rightTag = line.find(">");
                    if(rightTag == -1)
                    {
                        line.erase(0, line.size());
                        outFile << line;
                    } 

                    if(rightTag != -1)
                    {
                        line.erase(0, rightTag + 1);
                        outFile << line;
                    }

                    if(line.find('<') != string::npos)
                    {
                        break;
                    }
                    outFile << '\n' << endl;

                }

            }

                
                //här kan resultatsträngen pushas till output.


              
               
            



            






            /*


            if(!(leftTag == -1) && rightTag != -1)
            {

            


                int tagLength = rightTag - leftTag;
                cout << "The length of the tag is: " << tagLength << endl;

                line.erase(leftTag, tagLength + 1);

                cout << "line result is: " << line << endl;


                char TEST = line[leftTag];
                cout << "Test is: " << TEST << endl;



                //Här har vi en line, skall nu analysera denna linen.

                //För varje < måste vi hitta en >.
                //  unsigned int counter = 0;

                cout << "Current line: " << lineCounter << endl;

                cout << line << endl;






                ++lineCounter;
            }

            */


        }
    inFile.close();
    }
    else
    {
        cout << "Could not open file" << endl;
    }


    return 0;
}
