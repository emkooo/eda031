#include "bitreference.h"
#include "bitset.h"

BitReference& BitReference::operator=(bool b) {

b ? (*p_bits |= (1L << pos)) : (*p_bits &= ~ (1L << pos));
	return *this;
}

BitReference& BitReference::operator=(const BitReference& rhs) {

	rhs ? (*p_bits |= (1L << pos)) : (*p_bits &= ~ (1L << pos));
	return *this;
}

BitReference::operator bool() const { 

	return ((*p_bits & (1L << pos)) != 0); 
}
