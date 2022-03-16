#pragma once
// Implemintation of ordered Array List Type 
#include "orderedArrayListType.h"
#include "Implementation arrayListType  .h"
#include<iostream>
template <class ListItemType>
void orderedArrayListType<ListItemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cout << "The location of the item to be removed "
		<< "is out of range." << endl;
	else
	{
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
	}
} //end removeAt
template <class ListItemType>
orderedArrayListType<ListItemType> ::orderedArrayListType(int size) {
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

