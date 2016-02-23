/**************************************************
*
*	MNS.cc
*
**************************************************/

#include "mns.h"

using namespace std;

void 
MNS::insert(const HostName& hostAddr, const IPAddress& ipAddr)
{
	IPContainer.insert({hostAddr,ipAddr}); //Create object on the fly.
}

bool 
MNS::remove(const HostName& hostAddr)
{
	auto it = IPContainer.find(hostAddr);

	if(it != IPContainer.end())
	{
		IPContainer.erase (it);
		return true;
	}
	return false;
}

IPAddress 
MNS::lookup(const HostName& hostAddr) const	
{
	auto it = IPContainer.find(hostAddr);
	if(it != IPContainer.end())
	{
		return it->second;

	}
	return NON_EXISTING_ADDRESS;
}