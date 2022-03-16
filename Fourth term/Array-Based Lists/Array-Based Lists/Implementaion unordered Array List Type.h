#pragma once
// Implemintation of unordered Array List Type 
#include "unorderedArrayListType.h"
#include "Implementation arrayListType  .h"
#include<iostream>
template <class ListItemType>
void unorderedArrayListType<ListItemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cout << "The location of the item to be removed "
		<< "is out of range." << endl;
	else
	{
		list[location] = list[length - 1];
		length--;
	}
} //end removeAt
template <class ListItemType>
unorderedArrayListType<ListItemType> ::unorderedArrayListType(int size) {
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








