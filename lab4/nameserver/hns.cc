/**************************************************
*
*	HNS.cc
*
**************************************************/

#include "hns.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void 
HNS::insert(const HostName& hostAddr, const IPAddress& ipAddr)
{ 
	size_t hostHashValue = host_hash(hostAddr) % size;
	IPContainer[hostHashValue].emplace_back(hostAddr,ipAddr);
}

bool 
HNS::remove(const HostName& hostAddr)
{
	size_t hostHashValue = host_hash(hostAddr) % size;
	std::vector<std::pair<HostName,IPAddress>> v = IPContainer[hostHashValue];
	
	for(size_t i = 0; i < v.size(); i++)
	{
		if(v.at(i).first == hostAddr)
		{
			v.erase(v.begin() + i);
			return true;	
		}  
	}
	return false;
}

IPAddress 
HNS::lookup(const HostName& hostAddr) const
{
	size_t hostHashValue = host_hash(hostAddr) % size;
	std::vector<std::pair<HostName,IPAddress>> v = IPContainer[hostHashValue];

	for(size_t i = 0; i < v.size(); i++)
	{
		if(v.at(i).first == hostAddr) return v.at(i).second;
	}
	return NON_EXISTING_ADDRESS;
}
