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
	IPContainer.emplace_back(hostAddr,ipAddr);		//Constructs and inserts element att the back

}

bool 
VNS::remove(const HostName& hostAddr)
{
	//Går igenom listan, jobbbar med referensen, anv en curr som jämför om vi hittat rätt.
	auto it = find_if(IPContainer.begin(),IPContainer.end(),
								 [&] (pair<HostName,IPAddress> curr) ->bool {return curr.first == hostAddr;});
			
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
								[&] (pair<HostName,IPAddress> curr) ->bool {return curr.first == hostAddr;});
	if(it != IPContainer.end())
	{
		return it->second;
	}

	return NON_EXISTING_ADDRESS;
}