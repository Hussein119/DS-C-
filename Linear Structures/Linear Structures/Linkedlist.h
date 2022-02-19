#include <iostream>
#include<string>
#include "Node.h"
#include "List"
using namespace std;
template <class ListItemType>
class Linkedlist : public Node  {
public:
	Node* head;
	int listSize = 0;
	Linkedlist() { head = NULL; }
	inline bool isEmpty() { return head == NULL; }
	void push(int newData) {
		Node* newNode = new Node();
		newNode->data = newData;
		if (isEmpty()) {
			newNode->next = NULL;
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		listSize++;
	} // add to first '
	void insertAfter(Node* prevNode, int newData) {
		if (prevNode == NULL) return;
		Node* newNode = new Node();   // Allocate new node 
		newNode->data = newData;      // Put in the data 
		newNode->next = prevNode->next;  // Make next of new node as next of prev_node
		prevNode->next = newNode;       // move the next of prev_node as new_node 
		listSize++;
	}// add after current element 
	void append(Node** head_ref, int new_data)
	{
		Node* new_node = new Node();  // 1. allocate node      
		Node* last = *head_ref;       // Used in step 5 
		new_node->data = new_data;   // 2. Put in the data
		new_node->next = NULL;       // 3. This new node is going to be the last node, so make next of it as NULL 
		if (*head_ref == NULL)       // 4. If the Linked List is empty, then make the new node as head 
		{
			*head_ref = new_node;
			return;
		}
		while (last->next != NULL)   // 5. Else traverse till the last node 
		{
			last = last->next;
		}
		last->next = new_node;       // 6. Change the next of last node 
		return;
		listSize++;
	} // add after last element 
	int length() { return listSize; }    // Return list length 

	void deleteNode(Node* head, int position) {
		if (position == 0) {
			Node* curr = head->next; 
			delete head; 
			head = curr; 
			return head; 
		}
		else {
			Node* curr = head;
			for (int i = 0; i < position-1; i++) {
				curr = curr->next;
			}
			Node* temp = curr->next;
			curr->next = temp->next;
			delete temp; 
			return head; 


		}
	}



};