#pragma once
#include "arrayListType.h"
#include"Implementation arrayListType  .h"
template <class ListItemType>
class unorderedArrayListType : public arrayListType<ListItemType> {
public:
	void removeAt(int location);
	unorderedArrayListType(int size = 100);
	//Constructor
};
