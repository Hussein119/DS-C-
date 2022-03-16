#pragma once
#include "arrayListType.h"
template <class ListItemType>
class orderedArrayListType : public arrayListType
{
public:
	void removeAt(int location);
	orderedArrayListType(int size = 100);
	//Constructor
};