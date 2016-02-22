#ifndef UMNS_H
#define UMNS_H

#include "nameserverinterface.h"

class UMNS : public virtual NameServerInterface {
public:
	void insert(const HostName&, const IPAddress&) override;
	bool remove(const HostName&) override;
	IPAddress lookup(const HostName&) const override;

private:
};



#endif