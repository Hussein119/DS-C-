#include <bits/stdc++.h>
using namespace std; 
// Define the default capacity of the stack
#define SIZEStack 10
// Define the default capacity of a queue
#define SIZEQueue 1000
template <class ListItemType>
// A class to represent a stack 
class Stack {
    ListItemType* arr;
    ListItemType top; 
    int Stackcapacity;
public : 
    Stack(int Stacksize) {
        arr = new ListItemType[Stacksize];
        Stackcapacity = Stacksize;
        top = -1; 
    }
    ~Stack() {
        delete[] arr; 
    }
    void push(ListItemType it) {
        if (isFull()) {
            cout << " Overflow \n ";
            return; 
        }
        cout << "Inserting : " << it << endl;
        arr[++top] = it; 
    }
    int pop() {
        if (isEmpty()) {
            cout << " Underflow \n";
            return 0; 
        }
        cout << " Removing " << peek() << endl;
        return arr[top--]; 
    }
    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return 0; 
    }
    int size() {
        return top + 1; 
    }
    bool isEmpty() {
        return size() == 0; 
    }
    bool isFull() {
        return size() == Stackcapacity;
    }
};
template <class ListItemType>
// A class to store a queue
class Queue {
    ListItemType* arr; 
    int Queuecapacity;
    int head; 
    int tail; 
    int count; 

public : 
    Queue(int Queuesize ) {
        arr = new ListItemType[Queuesize];
        Queuecapacity = Queuesize; 
        head = 0; 
        tail = -1;
        count = 0; 
    }
    ~Queue() {
        delete[] arr; 
    }

    void enqueue(ListItemType it ) {
        if (isFull()) {
            cout << "Overflow \n ";
            return; 
        }
        cout << "Inserting : " << it << endl; 
        tail = (tail + 1) % Queuecapacity; 
        arr[tail] = it; 
        count++; 
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl; 
            return 0; 
        }
        ListItemType temp = arr[head];
        cout << "Removing " << temp << endl;
        head = (head + 1) % Queuecapacity; 
        count--; 
        return temp; 
    }
    int peek() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return 0; 
        }
        return arr[head]; 
    }
    int size() {
        return count; 
    }
    bool isEmpty() {
        return size() == 0; 
    }
    bool isFull() {
        return size() == Queuecapacity;
    }
};
int main()
{

 



    return 0; 
}

