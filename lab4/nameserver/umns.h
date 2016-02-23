#ifndef UMNS_H
#define UMNS_H

#include "nameserverinterface.h"
#include <unordered_map>

class UMNS : public virtual NameServerInterface {
public:
	void insert(const HostName&, const IPAddress&) override;
	bool remove(const HostName&) override;
	IPAddress lookup(const HostName&) const override;

private:
	std::unordered_map <HostName,IPAddress> IPContainer;
};



#endif