#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"

class VNS : public virtual NameServerInterface{
public:
	void insert(const HostName&, const IPAddress&) override;
	bool remove(const HostName&) override;
	IPAddress lookup(const HostName&) const override;


private:
};

#endif