#include <iostream>
#include "list.h"

using namespace std;

List::List() {

/*Empty list which makes
first == null and no other elements.*/

first = nullptr;

}

List::~List() {

	Node* temp = first->next;

while(first != nullptr){
	delete first;
	first = temp;
	temp = temp->next;
}

	

/* Guessing that if we delete the ptr knowing first
we will delete knowledge of the rest?*/
//first.delete;
}

bool List::exists(int d) const {

Node* temp = first;
	if(empty()){
		return false;
	}
	else{
		while(temp != nullptr){ 
			if(temp->value == d){
				return true;
			}
			temp = temp->next;
		}
	}


	return false;
}

int List::size() const
{

	if(first == nullptr){		//If list is empty
	
	return 0;					//return 0
}

else
{
	int size = 1;				//initiate counter
	Node* temp = first;			

	while(temp->next != nullptr)
{	//While there is more nodes.
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

void List::remove(int d, DeleteFlag df) //Implement for last element also?!?!
{
Node* temp = first->next;
Node* current = first; //

	switch(df)
	{
		case List::DeleteFlag::LESS:

	cout << "tell me it is ok" << endl;

	if(current->value < d){

		first = current->next;
		delete current;
		break;
	}

			while(temp != nullptr)
			{
					if(temp->value < d)
					{
						current->next = temp->next;
						delete temp;
	
					}
					current = temp;
					temp = temp->next;
					}
				break;

		case List::DeleteFlag::EQUAL:

		cout << "######" << endl;

	if(current->value == d){

		first = current->next;
		delete current;
		break;
	}
		while(temp != nullptr)
			{
					if(temp->value == d)
					{
						current->next = temp->next;
						delete temp;
						break;
	
					}

					current = temp;
					temp = temp->next;
					}
				break;

			case List::DeleteFlag::GREATER:

	if(current->value > d){
		first = current->next;
		delete current;
		break;
	}
			 cout << "333333" << endl;
			 while(temp != nullptr)
			 {
			 		if(temp->value > d)
			 		{
			 			current->next = temp->next;
			 			delete temp;
						break;
	
			 		}
						current = temp;
			 		temp = temp->next;
			 		}
			 	break;

	}
}

void List::print() const {
	Node* temp = first;
	cout << " " << endl;
	while(temp != nullptr){
		cout << temp->value << endl;
		temp = temp->next;
		
	}

}
