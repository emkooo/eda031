#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include <string>
#include <vector>
#include <unordered_set>


using namespace std;

class tagRemover {
public:
	tagRemover(fstream& inFile);
	void print();
    void removeSpecChar(string &thisLine);

private:

};

#endif
