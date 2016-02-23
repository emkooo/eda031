#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"
#include <vector>

class HNS : public virtual NameServerInterface {
public:
	HNS(std::size_t hashMapSize) : size(hashMapSize){ IPContainer.reserve(hashMapSize);};	//Allocate memory 
	void insert(const HostName&, const IPAddress&) override;
	bool remove(const HostName&) override;
	IPAddress lookup(const HostName&) const override;

private:
	std::size_t size;
	std::hash<std::string> host_hash;
	std::vector<std::vector<std::pair<HostName,IPAddress>>> IPContainer;
	
};


#endif