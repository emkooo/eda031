#ifndef MNS_H
#define MNS_H

#include "nameserverinterface.h"
#include <map>

class MNS : public virtual NameServerInterface{
public:
	void insert(const HostName&, const IPAddress&) override;
	bool remove(const HostName&) override;
	IPAddress lookup(const HostName&) const override;

private:
	std::map<HostName,IPAddress> IPContainer;
};



#endif