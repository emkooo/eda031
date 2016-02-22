#ifndef VNS_CC
#define VNS_CC




class VNS : public NameServerInterface{
public:
	VNS();
	test(VNS vns);
	//~NameServerInterface();
	void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;


private:
};




#endif