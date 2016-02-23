/**************************************************
*
*	UMNS.cc
*
**************************************************/

#include "umns.h"
#include <unordered_map>


void 
UMNS::insert(const HostName& hostAddr, const IPAddress& ipAddr)
{
	IPContainer.emplace(hostAddr,ipAddr);
}

bool 
UMNS::remove(const HostName& hostAddr)
{
	auto it = IPContainer.find(hostAddr);
	if(it != IPContainer.end())
	{
		IPContainer.erase(it);
		return true;
	}
	
	return false;
}

IPAddress 
UMNS::lookup(const HostName& hostAddr) const
{
	auto it = IPContainer.find(hostAddr);
	if(it != IPContainer.end())
	{
		return it->second;
	}

	return NON_EXISTING_ADDRESS;	
}