#pragma once
#include<string>
#include"List.h"
using namespace std; 
template <class ListItemType>
// Array-based list implementation
//class AList : public List 
class AList 
{
    ListItemType* listArray;            // Array holding list elements
    static const int DEFAULT_SIZE = 10; // Default size
    int maxSize;                        // Maximum size of list
    int listSize;                       // Current # of list items
    int curr;                           // Position of current element

public:
    // Constructors
    // Create a new list object with maximum size "size"
    AList(int size = DEFAULT_SIZE) : listSize(0), curr(0) {
        maxSize = size;
        listArray = new ListItemType[size];         // Create listArray
    }

    ~AList() { delete[] listArray; }      // destructor to remove array

    // Reinitialize the list
    void clear() { listSize = curr = 0; }  // Simply reinitialize values

    // Insert "it" at current position
    bool insert(const ListItemType& it) {
        if (listSize >= maxSize) return false;
        for (int i = listSize; i > curr; i--)  // Shift elements up
            listArray[i] = listArray[i - 1];       // to make room
        listArray[curr] = it;
        listSize++;                            // Increment list size
        return true;
    }

    // Append "it" to list
    bool append(const ListItemType& it) {
        if (listSize >= maxSize) return false;
        listArray[listSize++] = it;
        return true;
    }

    // Remove and return the current element
    ListItemType remove() {
        if ((curr < 0) || (curr >= listSize)) // No current element
            return;
        ListItemType it = listArray[curr];     // Copy the element
        for (int i = curr; i < listSize - 1; i++) // Shift them down
            listArray[i] = listArray[i + 1];
        listSize--;                            // Decrement size
        return it;
    }

    void moveToStart() { curr = 0; }       // Set to front
    void moveToEnd() { curr = listSize; }  // Set at end
    void prev() { if (curr != 0) curr--; } // Move left
    void next() { if (curr < listSize) curr++; } // Move right
    int length() { return listSize; }      // Return list size
    int currPos() { return curr; }         // Return current position

    // Set current list position to "pos"
    bool moveToPos(int pos) {
        if ((pos < 0) || (pos > listSize)) return false;
        curr = pos;
        return true;
    }

    // Return true if current position is at end of the list
    bool isAtEnd() { return curr == listSize; }

    // Return the current element
    ListItemType getValue() {
        if ((curr < 0) || (curr >= listSize)) // No current element
            return;
        return listArray[curr];
    }

    // Check if the list is empty
    bool isEmpty() { return listSize == 0; }
};

