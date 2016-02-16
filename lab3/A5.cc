#include <string>
#include <stdexcept>
#include "date.cc"
#include <sstream>

using namespace std;
template <typename T>
T string_cast(string toBeCasted)
{
	stringstream ss;
	ss << toBeCasted;
	T data;
	if(ss >> data)
	{
		return data;
	}
	else
	{
		throw invalid_argument("Cast of this type not supported");
	}
}


int main()
{
	try
	{	
		int i = string_cast<int>("123");
		cout << i << endl;
		double d = string_cast<double>("12.34");
		cout << d << endl;
		Date date = string_cast<Date>("2015-01-10");
		cout << date << endl;
	} 
	
	catch (invalid_argument& e) 
	{
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}