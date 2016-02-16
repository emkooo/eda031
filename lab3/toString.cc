#include <string>
#include <sstream>
#include <string>
#include "date.cc"

using namespace std;

// toString() template method.
template <typename T>
static string toString(const T& val)
{
	stringstream out;
	//argumenet object val inserted by <<
	out << val;
	return out.str();

}

int main()
{
	/* Check the toString template */
cout << "** Beginning of the toString() **" << endl;
   double d = 1.234;
   Date today;
   string sd = toString(d);
   string st = toString(today);
   cout << sd << "\n" << st << endl;
}