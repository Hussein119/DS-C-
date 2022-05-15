#include <bits/stdc++.h>
#include "Problem Solving.h"
using namespace std;
class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};
class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};
// some errors here 
//void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {         
//    while (node) {
//        fout << node->data;
//
//        node = node->next;
//
//        if (node) {
//            fout << sep;
//        }
//    }
//}
void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}
// print-the-elements-of-a-linked-list
void printLinkedList(SinglyLinkedListNode* head) {

    while (head != nullptr) {
        cout << head->data << endl;
        head = head->next;
    }

}

// insert-a-node-at-the-tail-of-a-linked-list 
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* it = new SinglyLinkedListNode(data);
    if (head == NULL) {
        head = it;
        return head;
    }
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = it;
    return head;
}

// insert-a-node-at-the-head-of-a-linked-list 
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {

    SinglyLinkedListNode* it = new SinglyLinkedListNode(data);
    it->next = llist;
    return it;

}

// insert - a - node - at - a - specific - position - in - a - linked - list

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* it = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* curr = head;
    if (position == 0) { head = it; }
    for (int i = 0; i < position - 1; i++)
    {
        curr = curr->next;
    }
    SinglyLinkedListNode* temp;
    temp = curr->next;
    curr->next = it;
    it->next = temp;
    return head;
}

// delete-a-node-from-a-linked-list 

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

    if (position == 0) {
        SinglyLinkedListNode* curr = head->next;
        delete head;
        head = curr;
        return head;
    }
    else {
        SinglyLinkedListNode* curr = head;
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }
        SinglyLinkedListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return head;
    }
}
// reverse Print 
void reversePrint(SinglyLinkedListNode* head) {
    if (head == NULL) {
        return;
    }
    reversePrint(head->next);
    cout << head->data << endl;

}

// reverse-a-linked-list 

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp1 = NULL;
    SinglyLinkedListNode* temp2 = NULL;
    while (head != NULL) {
        temp2 = head->next;
        head->next = temp1;
        temp1 = head;
        head = temp2;
    }
    return temp1;


} 

// compare-two-linked-lists

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int temp = 1;
    while (head1 != NULL || head2 != NULL) {
        if (head1 == NULL) { temp = 0; break; }
        if (head2 == NULL) { temp = 0; break; }
        if (head1->data != head2->data) { temp = 0; break; }
        head1 = head1->next;
        head2 = head2->next;
    }
    return temp;
}

// merge-two-sorted-linked-lists 
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* sorting = NULL;
    SinglyLinkedListNode* head = NULL;
    if (head1 == NULL) { return head2; }
    if (head2 == NULL) { return head1; }
    if (head1 && head2) {
        if (head1->data <= head2->data) {
            sorting = head1;
            head1 = sorting->next;
        }
        else {
            sorting = head2;
            head2 = sorting->next;
        }
    }
    head = sorting;
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            sorting->next = head1;
            sorting = head1;
            head1 = sorting->next;
        }
        else {
            sorting->next = head2;
            sorting = head2;
            head2 = sorting->next;
        }
    }
    if (head1 == NULL) { sorting->next = head2; }
    if (head2 == NULL) { sorting->next = head1; }
    return head;

}

// get-the-value-of-the-node-at-a-specific-position-from-the-tail 

int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* temp = head;
    int size = 0;
    while (temp != NULL) {
        temp = temp->next;
        size++;
    }
    size -= positionFromTail;
    temp = head;
    size--; // to stop at the wanted node 
    while (size != 0) {
        size--;
        temp = temp->next;
    }
    return temp->data;

}

// delete-duplicate-value-nodes-from-a-sorted-linked-list  
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* temp = NULL;
    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            temp = curr->next->next;
            delete curr->next;
            curr->next = temp;
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}
// has_cycle function 

bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp1 = head;
    SinglyLinkedListNode* temp2 = head;

    while (temp1 && temp2 && temp2->next)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;

        if (temp1 == temp2)
        {
            return 1;
        }
    }
    return 0;


}
class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class DoublyLinkedList {
public:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;

    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void insert_node(int node_data) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
            node->prev = this->tail;
        }

        this->tail = node;
    }
};
// some errors here 
//void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
//    while (node) {
//        fout << node->data;
//
//        node = node->next;
//
//        if (node) {
//            fout << sep;
//        }
//    }
//}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

int getCount(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* curr = head;
    int counter = 0;
    while (curr != NULL) {
        counter++;
        curr = curr->next;
    }
    return counter;
}
int getNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2, int d) {
    SinglyLinkedListNode* curr1 = head1;
    SinglyLinkedListNode* curr2 = head2;
    for (int i = 0; i < d; i++) {
        if (curr1 == NULL) return 0;
        curr1 = curr1->next;
    }
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1 == curr2) return curr1->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return 0;
}
int getCount(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* curr = head;
    int counter = 0;
    while (curr != NULL) {
        counter++;
        curr = curr->next;
    }
    return counter;
}
DoublyLinkedListNode* insertfirst(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* it = new  DoublyLinkedListNode(data);
    it->next = head;
    head->prev = it;
    it->prev = NULL;
    head = it;
    return head;
}
DoublyLinkedListNode* insertInternal(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* curr = head;
    DoublyLinkedListNode* it = new  DoublyLinkedListNode(data);
    DoublyLinkedListNode* temp;
    temp = curr->next;
    curr->next = it;
    it->prev = curr;
    it->next = temp;
    temp->prev = it;
    return head;
}
DoublyLinkedListNode* insertlast(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* curr = head;
    DoublyLinkedListNode* it = new  DoublyLinkedListNode(data);
    int length = getCount(head);
    for (int i = 0; i < length; i++) {
        if (curr->next->data > it->data) {
            insertInternal(head, data);
        }
    }
    return head;
}

// reverse function Doubly Linked List 
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* ptr1 = head;
    DoublyLinkedListNode* ptr2 = head->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2 != NULL) {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}
class Node {
public:
    int data;
    Node* next;
};
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

// Check for Balanced Brackets 
void isBalanced(string s) {
    stack <char> br;
    int size = s.size();
    char temp;
    if (size % 2 == 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            br.push(s[i]);
        }
        if (br.empty()) {
            cout << "NO\n";
            return;
        }
        if (s[i] == ')') {
            temp = br.top();
            br.pop();
            if (temp == '{' || temp == '[')
            {
                cout << "NO\n";
                return;
            }
        }
        if (s[i] == ']') {
            temp = br.top();
            br.pop();
            if (temp == '{' || temp == '(')
            {
                cout << "NO\n";
                return;
            }
        }
        if (s[i] == '}') {
            temp = br.top();
            br.pop();
            if (temp == '(' || temp == '[')
            {
                cout << "NO\n";
                return;
            }
        }
    }
    if (br.empty())
    {
        cout << "YES\n";
        return;
    }
    else {
        cout << "NO\n";
        return;
    }
}

// Returns maximum possible equal sum of three stacks
// with removal of top elements allowed
int equalStacks(int stack1[], int stack2[], int stack3[], int n1, int n2, int n3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;

    // Finding the initial sum of stack1.
    for (int i = 0; i < n1; i++)
        sum1 += stack1[i];

    // Finding the initial sum of stack2.
    for (int i = 0; i < n2; i++)
        sum2 += stack2[i];

    // Finding the initial sum of stack3.
    for (int i = 0; i < n3; i++)
        sum3 += stack3[i];

    // As given in question, first element is top of stack..
    int top1 = 0, top2 = 0, top3 = 0;
    while (1) {
        // If any stack is empty
        if (top1 == n1 || top2 == n2 || top3 == n3)
            return 0;

        // If sum of all three stack are equal.
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;

        // Finding the stack with maximum sum and removing its top element.
        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= stack1[top1++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= stack2[top2++];
        else if (sum3 >= sum2 && sum3 >= sum1)
            sum3 -= stack3[top3++];
    }
}
// https://ideone.com/GElF9q  // test 
int stack1[99999];
int stack2[99999];
int stack3[99999];


// game-of-two-stacks 
int twoStacks(int maxSum, int l1 , int l2, vector<int> a, vector<int> b) {
    int result = 0 , st1counter = 0, st2counter = 0, sum = 0; 

    // get elements form first stack 
    for (int i = 0; i < l1; i++) {
        if (sum + a[i] > maxSum) {
            break;
        }
        sum += a[i];
        st1counter++;
    }
    result = st1counter; 

    // get elements form second stack 

    for (int i = 0; i < l2; i++) {
        sum += b[i];
        st2counter++;
        while (sum > maxSum && st1counter > 0) {
            sum -= a.at(st1counter - 1);
            st1counter--;
        }
        if (sum <= maxSum) {
            result = max((st1counter + st2counter), result);
        }

    }
    return result; 

}

// queue-using-two-stacks 
template <class ListItemType>
// A class to store a queue
class Queue {
    ListItemType* arr;
    int Queuecapacity;
    int head;
    int tail;
    int count;
public:
    Queue(int Queuesize) {
        arr = new ListItemType[Queuesize];
        Queuecapacity = Queuesize;
        head = 0;
        tail = -1;
        count = 0;
    }
    ~Queue() {
        delete[] arr;
    }
    void enqueue(ListItemType it) {
        if (isFull()) {
            cout << "Overflow \n ";
            return;
        }
        //cout << "Inserting : " << it << endl; 
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
        // cout << "Removing " << temp << endl;
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
Queue<int> Q(9999999);


// largest-rectangle/problem 
long largestRectangle(vector<int> h) {
    int size = h.size();
    stack <int> s;
    long maxarea = 0;
    for (int i = 0; i <= size; i++) {
        while (!s.empty() && (i == size || (h[s.top()] >= h[i]))) {
            long height = h[s.top()];
            s.pop();
            long width; 
            if (s.empty()) width = i;
            else width = i - s.top() - 1;
            maxarea = max(maxarea, width * height);
        }
        s.push(i);
    }
    return maxarea;
}








int main()
{
    
    //// print-the-elements-of-a-linked-list 
    // 
    //SinglyLinkedList* llist = new SinglyLinkedList();

    //int llist_count;
    //cin >> llist_count;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //for (int i = 0; i < llist_count; i++) {
    //    int llist_item;
    //    cin >> llist_item;
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //    llist->insert_node(llist_item);
    //}

    //printLinkedList(llist->head);      some errors here 

    // insert-a-node-at-the-tail-of-a-linked-list 

    /*ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head, "\n", fout);
    fout << "\n";

    free_singly_linked_list(llist->head);

    fout.close();*/

    // insert-a-node-at-the-head-of-a-linked-list     some errors here 

    /*ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedListNode* llist_head = insertNodeAtHead(llist->head, llist_item);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head, "\n", fout);
    fout << "\n";

    free_singly_linked_list(llist->head);

    fout.close();*/

    // insert-a-node-at-a-specific-position-in-a-linked-list         some errors here 

    /*ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();*/

     
     // delete-a-node-from-a-linked-list              some errors here 
    /* ofstream fout(getenv("OUTPUT_PATH"));
    SinglyLinkedList* llist = new SinglyLinkedList();
     int llist_count;
     cin >> llist_count;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     for (int i = 0; i < llist_count; i++) {
       int llist_item;
       cin >> llist_item;
       cin.ignore(numeric_limits<streamsize>::max(), '\n');

       llist->insert_node(llist_item);
     }
      int position;
      cin >> position;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      SinglyLinkedListNode* llist1 = deleteNode(llist->head, position);
      print_singly_linked_list(llist1, " ", fout);
      fout << "\n";
       free_singly_linked_list(llist1);
       fout.close();*/

         // reverse Print
     /* int tests;
      cin >> tests;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
      SinglyLinkedList* llist = new SinglyLinkedList();

      int llist_count;
      cin >> llist_count;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
     }

       reversePrint(llist->head);
  }*/
           
 
           // reverse-a-linked-list              some errors here 
//ofstream fout(getenv("OUTPUT_PATH"));
//
//int tests;
//cin >> tests;
//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
//    SinglyLinkedList* llist = new SinglyLinkedList();
//
//    int llist_count;
//    cin >> llist_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist_count; i++) {
//        int llist_item;
//        cin >> llist_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist->insert_node(llist_item);
//    }
//
//    SinglyLinkedListNode* llist1 = reverse(llist->head);
//
//    print_singly_linked_list(llist1, " ", fout);
//    fout << "\n";
//
//    free_singly_linked_list(llist1);
//}
//
//fout.close();
              
          // compare-two-linked-lists      some errors here
//ofstream fout(getenv("OUTPUT_PATH"));
//
//int tests;
//cin >> tests;
//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
//    SinglyLinkedList* llist1 = new SinglyLinkedList();
//
//    int llist1_count;
//    cin >> llist1_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist1_count; i++) {
//        int llist1_item;
//        cin >> llist1_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist1->insert_node(llist1_item);
//    }
//
//    SinglyLinkedList* llist2 = new SinglyLinkedList();
//
//    int llist2_count;
//    cin >> llist2_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist2_count; i++) {
//        int llist2_item;
//        cin >> llist2_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist2->insert_node(llist2_item);
//    }
//
//    bool result = compare_lists(llist1->head, llist2->head);
//
//    fout << result << "\n";
//}
//
//fout.close();
 
            // merge-two-sorted-linked-lists        some errors here 
//ofstream fout(getenv("OUTPUT_PATH"));
//
//int tests;
//cin >> tests;
//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
//    SinglyLinkedList* llist1 = new SinglyLinkedList();
//
//    int llist1_count;
//    cin >> llist1_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist1_count; i++) {
//        int llist1_item;
//        cin >> llist1_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist1->insert_node(llist1_item);
//    }
//
//    SinglyLinkedList* llist2 = new SinglyLinkedList();
//
//    int llist2_count;
//    cin >> llist2_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist2_count; i++) {
//        int llist2_item;
//        cin >> llist2_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist2->insert_node(llist2_item);
//    }
//
//    SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);
//
//    print_singly_linked_list(llist3, " ", fout);
//    fout << "\n";
//
//    free_singly_linked_list(llist3);
//}
//
//fout.close();
              
               // get-the-value-of-the-node-at-a-specific-position-from-the-tail    some errors here 
//ofstream fout(getenv("OUTPUT_PATH"));
//
//int tests;
//cin >> tests;
//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
//    SinglyLinkedList* llist = new SinglyLinkedList();
//
//    int llist_count;
//    cin >> llist_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist_count; i++) {
//        int llist_item;
//        cin >> llist_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist->insert_node(llist_item);
//    }
//
//    int position;
//    cin >> position;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    int result = getNode(llist->head, position);
//
//    fout << result << "\n";
//}
//
//fout.close(); 
                 

               // delete-duplicate-value-nodes-from-a-sorted-linked-list    some errors here 
//ofstream fout(getenv("OUTPUT_PATH"));
//
//int t;
//cin >> t;
//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//for (int t_itr = 0; t_itr < t; t_itr++) {
//    SinglyLinkedList* llist = new SinglyLinkedList();
//
//    int llist_count;
//    cin >> llist_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist_count; i++) {
//        int llist_item;
//        cin >> llist_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist->insert_node(llist_item);
//    }
//
//    SinglyLinkedListNode* llist1 = removeDuplicates(llist->head);
//
//    print_singly_linked_list(llist1, " ", fout);
//    fout << "\n";
//
//    free_singly_linked_list(llist1);
//}
//
//fout.close();
                
                 // has_cycle function main    some errors here 

//ofstream fout(getenv("OUTPUT_PATH"));
//
//int tests;
//cin >> tests;
//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
//    int index;
//    cin >> index;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    SinglyLinkedList* llist = new SinglyLinkedList();
//
//    int llist_count;
//    cin >> llist_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist_count; i++) {
//        int llist_item;
//        cin >> llist_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist->insert_node(llist_item);
//    }
//
//    SinglyLinkedListNode* extra = new SinglyLinkedListNode(-1);
//    SinglyLinkedListNode* temp = llist->head;
//
//    for (int i = 0; i < llist_count; i++) {
//        if (i == index) {
//            extra = temp;
//        }
//
//        if (i != llist_count - 1) {
//            temp = temp->next;
//        }
//    }
//
//    temp->next = extra;
//
//    bool result = has_cycle(llist->head);
//
//    fout << result << "\n";
//}
//
//fout.close();


               // reverse function Doubly Linked List 
//ofstream fout(getenv("OUTPUT_PATH"));
//
//int t;
//cin >> t;
//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//for (int t_itr = 0; t_itr < t; t_itr++) {
//    DoublyLinkedList* llist = new DoublyLinkedList();
//
//    int llist_count;
//    cin >> llist_count;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    for (int i = 0; i < llist_count; i++) {
//        int llist_item;
//        cin >> llist_item;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        llist->insert_node(llist_item);
//    }
//
//    DoublyLinkedListNode* llist1 = reverse(llist->head);
//
//    print_doubly_linked_list(llist1, " ", fout);
//    fout << "\n";
//
//    free_doubly_linked_list(llist1);
//}
//
//fout.close();


//int t; cin >> t;
//Stack <int> s;
//while (t--) {
//    int c; cin >> c;
//    if (c == 1) {
//        int input; cin >> input;
//        s.push(input);
//    }
//    else if (c == 2) {
//        s.pop();
//    }
//    else if (c == 3) {
//        cout << s.peek() << endl;
//    }
//}


// isBalanced brackets 
//int t; cin >> t;
//for (int i = 0; i < t; i++) {
//    string s;
//    cin >> s;
//    isBalanced(s);
//}

//int n1, n2, n3;
//cin >> n1; cin >> n2; cin >> n3;
//int x1;
//for (int i = 0; i < n1; i++) {
//    cin >> x1;
//}
//int x2;
//for (int i = 0; i < n2; i++) {
//    cin >> x2;
//}
//int x3;
//for (int i = 0; i < n3; i++) {
//    cin >> x3;
//}
//cout << equalStacks(n1, n2, n3);

// equal-stacks 
//int n1; cin >> n1;
//int n2; cin >> n2;
//int n3; cin >> n3;
//
//for (int i = 0; i < n1; i++) {
//    cin >> stack1[i];
//}
//for (int i = 0; i < n2; i++) {
//    cin >> stack2[i];
//}
//for (int i = 0; i < n3; i++) {
//    cin >> stack3[i];
//}
//cout << equalStacks(stack1, stack2, stack3, n1, n2, n3) << endl;



//// game-of-two-stacks 
//int t; cin >> t; 
//for (int i = 0; i < t; i++) {
//    vector <int> s1;
//    vector <int> s2;
//    int l1, l2, maxx;
//    cin >> l1 >> l2 >> maxx; 
//    for (int i = 0; i < l1; i++) {
//        int x1; cin >> x1; 
//        s1.push_back(x1);
//    }
//    for (int i = 0; i < l2; i++) {
//        int x2; cin >> x2;
//        s2.push_back(x2);
//    }
//    cout << twoStacks(maxx,l1,l2 ,s1, s2) << endl;
//}

//// queue-using-two-stacks 
//int numberOfqueries; cin >> numberOfqueries;
//int process;
//while (numberOfqueries--) {
//    cin >> process;
//    if (process == 1) {
//        int data; cin >> data;
//        Q.enqueue(data);
//    }
//    if (process == 2) {
//        Q.dequeue();
//    }
//    if (process == 3) {
//        cout << Q.peek() << endl;
//    }
//}
 





	return 0; 
}


