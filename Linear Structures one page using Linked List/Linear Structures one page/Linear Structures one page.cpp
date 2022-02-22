//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// singly linked list implementation ____________________________________________________________________________
class Node {
public:
	int data;
	Node* next;
};
template <class ListItemType>
class Linkedlist : public Node {
public:
	Node* head;
	int listSize = 0;
	Linkedlist() { head = NULL; }
	inline bool isEmpty() { return head == NULL; }
	void push(ListItemType newData) {
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
	void insertAfter(Node* prevNode, ListItemType newData) {
		if (prevNode == NULL) return;
		Node* newNode = new Node();   // Allocate new node 
		newNode->data = newData;      // Put in the data 
		newNode->next = prevNode->next;  // Make next of new node as next of prev_node
		prevNode->next = newNode;       // move the next of prev_node as new_node 
		listSize++;
	}// add after current element 
	void append(Node** head_ref, ListItemType new_data)
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
			for (int i = 0; i < position - 1; i++) {
				curr = curr->next;
			}
			Node* temp = curr->next;
			curr->next = temp->next;
			delete temp;
			return head;
		}
	}
};
// doubly linked list implementation ______________________________________________________________________________
template <class ListItemType>
class DoublyLinkedListNode {
public:
	int data;
	DoublyLinkedListNode* next;
	DoublyLinkedListNode* prev;

	DoublyLinkedListNode(ListItemType node_data) {
		this->data = node_data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};
template <class ListItemType>
class DoublyLinkedList {
public:
	DoublyLinkedListNode* head;
	DoublyLinkedListNode* tail;
	DoublyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}
	DoublyLinkedList* GetNewNode(ListItemType n)
	{
		DoublyLinkedList* newNode = new DoublyLinkedList();
		newNode->data = n;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
	void InsertAtHead(ListItemType n)
	{
		DoublyLinkedListNode* temp = GetNewNode(n);
		if (head == NULL)
		{
			head = temp;
			return;
		}
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	void print()
	{
		DoublyLinkedListNode* t = head;
		cout << "Forward: ";
		while (t != NULL)
		{
			cout << t->data << " ";
			t = t->next;
		}
		cout << "\n";
	}
	void print_reverse()
	{
		DoublyLinkedListNode* t = head;
		while (t->next != NULL)
		{
			t = t->next;
		}
		//reverse
		cout << "reverse: ";
		while (t != NULL)
		{
			cout << t->data << " ";
			t = t->prev;
		}
		cout << "\n";
	}
};
// Stack implementation_____________________________________________________________________________________________ 
template <class ListItemType>
class Stack {
	Node* top;
public:
	bool  isEmpty() { return top == NULL; }
	void push(ListItemType data) {
		Node* it = new Node(); 
		it->data = data;
		it->next = top;
		top = it;
	}
	int pop() {
		if (isEmpty()) return 0;
		Node* temp = top;
		ListItemType item = temp->data;
		top = top->next;
		delete temp;
		return item;
	}
	void display() {
		Node* temp = top;
		while (temp != NULL) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	int peek() {
		if (isEmpty()) return 0;
		return top->data;
	}
};
// Queues implementation_____________________________________________________________________________________________
template <class ListItemType>
class Queues {
public : 
	Node* head;
	Node* tail;
	int Queuesize = 0;
	Queues() {
		head = tail = NULL; 
	}

	void Enqueue(ListItemType data) {
		Node* it = new Node();
		it->data = data; 
		if (isEmpty()) {
			head = it; 
			tail = it; 
			Queuesize++;
		}
		tail->next = it; 
		tail = it; 
		Queuesize++; 
	}
	void Dequeue() {
		if (isEmpty()) { return; }
		if (head == tail) {
			delete head; 
			head = tail = NULL;
			Queuesize--;
		}
		Node* temp = head; 
		head = head->next; 
		delete temp; 

		Queuesize--;
	}
	bool isEmpty() { return (head == NULL && tail == NULL); }
	ListItemType peek() { return head->data; }
	int length() { return Queuesize;  }
	void clear() {
		if (isEmpty()) { return; }
		while (!isEmpty()) {
			Dequeue();
		}
	} 
	void display() {
		if (isEmpty()) { cout << "Queue is empty  \n"; }
		Node* curr = head; 
		while (curr != NULL) {
			cout << curr->data << "  ";
			curr = curr->next; 
		}
		cout << endl; 
	}
};
int main()
{
	




    return 0; 
}

