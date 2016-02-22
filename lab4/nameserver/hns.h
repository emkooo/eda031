#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"

class HNS : public virtual NameServerInterface {
public:
	HNS(unsigned long hashMapSize) : size(hashMapSize){};
	void insert(const HostName&, const IPAddress&) override;
	bool remove(const HostName&) override;
	IPAddress lookup(const HostName&) const override;

private:
	size_t size;
};



#endif