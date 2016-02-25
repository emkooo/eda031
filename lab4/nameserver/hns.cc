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
	std::vector<std::pair<HostName,IPAddress>>& v = IPContainer[hostHashValue];

	auto it = find_if(v.begin(),v.end(),
								 [&] (std::pair<HostName,IPAddress> curr) ->bool {return curr.first == hostAddr;});

		if(it != v.end())
	{
		v.erase(it);
		return true;
	}											
	return false;
}

IPAddress 
HNS::lookup(const HostName& hostAddr) const
{
	size_t hostHashValue = host_hash(hostAddr) % size;
	const std::vector<std::pair<HostName,IPAddress>>& v = IPContainer[hostHashValue];

	auto it = find_if(v.begin(),v.end(),
								 [&] (std::pair<HostName,IPAddress> curr) ->bool {return curr.first == hostAddr;});

		if(it != v.end())
	{	
		return it->second;
	}											
	return NON_EXISTING_ADDRESS;
}

