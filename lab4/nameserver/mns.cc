/**************************************************
*
*	MNS.cc
*
**************************************************/

#include "mns.h"


void 
MNS::insert(const HostName&, const IPAddress&)
{
}

bool 
MNS::remove(const HostName&)
{
	return false;
}

IPAddress 
MNS::lookup(const HostName&) const	
{
	return 0;
}