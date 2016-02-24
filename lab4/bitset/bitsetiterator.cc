#include "bitset.h"
#include "bitreference.h"
#include "bitsetiterator.h"

BItSetIterator::BitsetIterator(Bitset::BitStorage* pb, std::size_t p) : ref(pb, p) {}
	
	bool BItSetIterator::operator!=(const BitsetIterator& bsi) const {
		return true;
	}
	
	BitsetIterator& BItSetIterator::operator++() {
		return *this;
	}
	
	BitReference BItSetIterator::operator*() {
		return ref;
	}
	
	BitsetIterator& BItSetIterator::operator=(const BitsetIterator& rhs) { 

	}
