#include <iostream>
#include "list.h"



List::List() {

/*Empty list which makes
first == null and no other elements.*/

first = nullptr;

}

List::~List() {

/* Guessing that if we delete the ptr knowing first
we will delete knowledge of the rest?*/
//first.delete;
}

bool List::exists(int d) const {
	return true;
}

int List::size() const {

if(first == nullptr){		//If list is empty
return 0;					//return 0
}
else{
int size = 0;				//initiate counter
Node* temp = first;			

while(temp->next != nullptr){	//While there is more nodes.
temp = temp->next;				//go to next node
size++;							//add 1 node in size.
}
return size; 
	}
}

bool List::empty() const {
	
return (first == nullptr);		//if first == null empty, else not.

}

void List::insertFirst(int d) {

Node* n = new Node(d,first);		//Create a new Node with value (d) next node *(first)
									
first = n;				//The first node is now the created node.


}

void List::remove(int d, DeleteFlag df) {
}

void List::print() const {
}

