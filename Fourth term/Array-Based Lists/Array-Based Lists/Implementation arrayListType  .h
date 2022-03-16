#pragma once
// Implemintation of array list type 
#include "arrayListType.h"
#include<iostream>
using namespace std; 
template <class ListItemType>
inline bool arrayListType<ListItemType>::isEmpty() const
{
	return (length == 0);
} //end isEmpty
template <class ListItemType>
inline bool arrayListType<ListItemType>::isFull() const
{
	return (length == maxSize);
} //end isFull
template <class ListItemType>
inline ListItemType arrayListType<ListItemType>::listSize() const
{
	return length;
}   //end listSize
template <class ListItemType>
inline ListItemType arrayListType<ListItemType>::maxListSize() const
{
	return maxSize;
} //end maxListSize
template <class ListItemType>
void arrayListType<ListItemType>::print() const
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
} //end print
template <class ListItemType>
bool arrayListType<ListItemType>::isItemAtEqual(int location, ListItemType item) const
{
	if ( (location < 0 || location >= length ) )
	{
		cout << "The location of the item to be removed is out of range." << endl;
		return false;
	}
	else
		return (list[location] == item);
} //end isItemAtEqual
template <class ListItemType>
void arrayListType<ListItemType>::retrieveAt(int location, ListItemType& retItem) const
{
	if (location < 0 || location >= length)
		cout << "The location of the item to be retrieved is "
		<< "out of range" << endl;
	else
		retItem = list[location];
} //end retrieveAt
template <class ListItemType>
void arrayListType<ListItemType>::replaceAt(int location, ListItemType repItem)
{
	if (location < 0 || location >= length)
		cout << "The location of the item to be "
		<< "replaced is out of range." << endl;
	else
		list[location] = repItem;
} //end replaceAt
template <class ListItemType>
void arrayListType<ListItemType>::insertEnd(ListItemType insertItem)
{
	if (isFull()) //the list is full
		cout << "Cannot insert in a full list." << endl;
	else
	{
		list[length] = insertItem; //insert the item at the end
		length++; //increment the length
	}
} //end insertEnd
template <class ListItemType>
void arrayListType<ListItemType>::insertAt(int location, ListItemType insertItem)
{
	if (location < 0 || location >= maxSize)
		cout << "The position of the item to be inserted "
		<< "is out of range." << endl;
	else if (isFull())   //list is full
		cout << "Cannot insert in a full list. " << endl;
	else
	{
		for (int i = length; i > location; i--)
			list[i] = list[i - 1]; //move the elements down
		list[location] = insertItem; //insert the item at the specified position
		length++; //increment the length
	}
} //end insertAt
template <class ListItemType>
void arrayListType<ListItemType>::insert(ListItemType insertItem)
{
	if (length == 0) //list is empty
		list[length++] = insertItem;//insert insertItem
		//and increment length
	else if (length == maxSize)
		cout << "Cannot insert in a full list." << endl;
	else
	{
		//Find the location in the list where to insert
		//insertItem.
		int loc;
		bool found = false;
		for (loc = 0; loc < length; loc++)
		{
			if (list[loc] == insertItem)
			{
				found = true;
				break;
			}
		}
		for (int i = length; i = loc; i--)
			list[i] = list[i - 1];//move the elements down
		list[loc] = insertItem;//insert insertItem
		length++; //increment the length
	}
} //end insert
template <class ListItemType>
void arrayListType<ListItemType>::clearList()
{
	length = 0;
} //end clearList
template <class ListItemType>
ListItemType arrayListType<ListItemType>::seqSearch(ListItemType searchItem) const
{
	int loc;
	bool found = false;
	loc = 0;
	while (loc < length && !found)
		if (list[loc] == searchItem)
			found = true;
		else
			loc++;
	if (found)
		return loc;
	else
		return -1;
} //end seqSearch
template <class ListItemType>
void arrayListType<ListItemType>::remove(ListItemType removeItem)
{
	int loc;
	if (isEmpty())
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the list." << endl;
	}
} //end remove
template <class ListItemType>
arrayListType<ListItemType>::arrayListType(int size)
{
	if (size <= 0)
	{
		cout << "The array size must be positive. Creating an array of the size 100." << endl;
			maxSize = 100;
	}
	else
		maxSize = size;
	length = 0;
	list = new ListItemType[maxSize];
} //end constructor
template <class ListItemType>
arrayListType<ListItemType>::~arrayListType()
{
	delete[] list;
} //end destructor
template <class ListItemType>
arrayListType<ListItemType>::arrayListType(const arrayListType<ListItemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new ListItemType[maxSize]; //create the array
	for (int j = 0; j < length; j++) //copy otherList
		list[j] = otherList.list[j];
}//end copy constructor

