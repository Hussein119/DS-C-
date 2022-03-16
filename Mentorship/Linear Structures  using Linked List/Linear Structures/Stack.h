//#include <bits/stdc++.h>
#include"Node.h"
#include <cstddef>
#include<iostream>
using namespace std;
class Stack {
	Node* top;
	int size = 0;
public : 
	bool  isEmpty() { return top == NULL; }
	void push(int data) {
		Node* it = new Node();
		it->data = data;
		it->next = top;
		top = it;
		cout << "Pushing : " << top->data << endl;
		size++; 

	}
	int pop() {
		if (isEmpty()) return 0; 
		Node* temp = top; 
		int item = temp->data; 
		top = top->next;  
		delete temp; 
		cout << " removing : " << item << endl;
		size--; 
		return item; 
		
	}
	void display() {
		Node* temp = top; 
		for (int i = 0; i < size; i++) {
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