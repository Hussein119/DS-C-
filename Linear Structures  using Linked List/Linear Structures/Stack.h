#include <bits/stdc++.h>
#include"Node.h"
using namespace std;
class Stack {
	Node* top; 
public : 
	bool  isEmpty() { return top == NULL; }
	void push(int data) {
		Node* it;
		it->data = data;
		it->next = top;
		top = it;
	}
	int pop() {
		if (isEmpty()) return 0; 
		Node* temp = top; 
		int item = temp->data; 
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