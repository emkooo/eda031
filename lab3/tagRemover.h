#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include <string>
#include <vector>
#include <unordered_set>


using namespace std;

class tagRemover {
public:
	tagRemover(istream& inFile);
	void print(ostream& outFile);
    void removeSpecChar(string &thisLine);

private:
};

#endif
