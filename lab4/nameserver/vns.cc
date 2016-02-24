/*****************************************************************
*
*	VNS.cc
*
*****************************************************************/
#include "vns.h"
#include <algorithm>

void 
VNS::insert(const HostName& hostAddr, const IPAddress& ipAddr)
{
	IPContainer.emplace_back(hostAddr,ipAddr);		

}

bool 
VNS::remove(const HostName& hostAddr)
{
	auto it = find_if(IPContainer.begin(),IPContainer.end(),
								 [&] (std::pair<HostName,IPAddress> curr) ->bool {return curr.first == hostAddr;});
			
	if(it != IPContainer.end())
	{
		IPContainer.erase(it);
		return true;
	}											
	return false;
}

IPAddress 
VNS::lookup(const HostName& hostAddr) const
{
	auto it = std::find_if(IPContainer.begin(),IPContainer.end(),
								[&hostAddr] (std::pair<HostName,IPAddress> curr) ->bool {return curr.first == hostAddr;});

	return (it != IPContainer.end() ? it->second : NON_EXISTING_ADDRESS);
}